cmake_minimum_required(VERSION 3.27)
project(TorchCS-Logger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/out/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_SYSTEM_NAME}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

find_package(spdlog CONFIG REQUIRED)

option(BUILD_SHARED_LIBS "Build as a shared library (.so/.dll instead of .a/.lib)" OFF)

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

add_executable(TorchCS-Logger_Test tests/main.cpp)
target_link_libraries(TorchCS-Logger_Test PRIVATE TorchCS-Logger spdlog::spdlog)

if(WIN32)
    message(STATUS "Configuring for Windows...")
elseif(UNIX)
    message(STATUS "Configuring for Linux...")
    target_link_libraries(TorchCS-Logger PRIVATE pthread)
endif()

if(TARGET TorchCS-Logger)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(TorchCS-Logger PRIVATE -Wall -Wextra -Wpedantic)
    elseif(MSVC)
        target_compile_options(TorchCS-Logger PRIVATE /W4)
    endif()
endif()
