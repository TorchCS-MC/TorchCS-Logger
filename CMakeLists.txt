cmake_minimum_required(VERSION 3.27)
project(TorchCS-Logger)

include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(spdlog CONFIG REQUIRED)

option(BUILD_SHARED_LIBS "Build as a shared library (.so/.dll instead of .a/.lib)" OFF)
option(BUILD_TESTS "Enable tests" ON)

add_library(TorchCS-Logger
        src/LoggerManager.cpp
        src/LoggerOptions.cpp
        src/CustomFormatter.cpp
        src/LogColor.cpp
)

target_include_directories(TorchCS-Logger PUBLIC include)
target_link_libraries(TorchCS-Logger PRIVATE spdlog::spdlog)

install(TARGETS TorchCS-Logger
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include
)

if(WIN32)
    message(STATUS "Configuring for Windows...")
    add_definitions(-D_WIN32)
elseif(UNIX)
    message(STATUS "Configuring for Linux...")
    target_link_libraries(TorchCS-Logger PRIVATE pthread)
endif()

if(TARGET TorchCS-Logger)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(TorchCS-Logger PRIVATE -Wall -Wextra -Wpedantic -Werror)
    elseif(MSVC)
        target_compile_options(TorchCS-Logger PRIVATE /W4 /WX)
    endif()
endif()

if(BUILD_TESTS)
    enable_testing()
    add_executable(TorchCS-Logger_Test tests/main.cpp)
    target_link_libraries(TorchCS-Logger_Test PRIVATE TorchCS-Logger spdlog::spdlog)
    add_test(NAME LoggerTests COMMAND TorchCS-Logger_Test)
endif()