cmake_minimum_required(VERSION 3.27)
project(TorchCS-Logger VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(TORCHCS_LOGGER_INSTALL "Enable installation of TorchCS-Logger" ON)
option(TORCHCS_LOGGER_SHARED "Build TorchCS-Logger as a shared library (.so/.dll)" OFF)
option(TORCHCS_LOGGER_STATIC "Build TorchCS-Logger as a static library (.a/.lib)" ON)
option(TORCHCS_LOGGER_EXECUTABLE "Build TorchCS-Logger as an executable" OFF)

if(TORCHCS_LOGGER_SHARED AND TORCHCS_LOGGER_STATIC)
    message(FATAL_ERROR "Both TORCHCS_LOGGER_SHARED and TORCHCS_LOGGER_STATIC are enabled. Choose only one.")
endif()

if(TORCHCS_LOGGER_SHARED)
    set(LIBRARY_TYPE SHARED)
    message(STATUS "Building TorchCS-Logger as a shared library")
elseif(TORCHCS_LOGGER_STATIC)
    set(LIBRARY_TYPE STATIC)
    message(STATUS "Building TorchCS-Logger as a static library")
else()
    message(FATAL_ERROR "Either TORCHCS_LOGGER_SHARED or TORCHCS_LOGGER_STATIC must be enabled.")
endif()

find_package(spdlog CONFIG REQUIRED)

add_library(TorchCS-Logger ${LIBRARY_TYPE}
    src/logger_manager.cpp
    src/logger_options.cpp
    src/custom_formatter.cpp
    src/log_color.cpp
)

target_include_directories(TorchCS-Logger PUBLIC include)
target_link_libraries(TorchCS-Logger PRIVATE spdlog::spdlog)

if(TARGET TorchCS-Logger)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(TorchCS-Logger PRIVATE -Wall -Wextra -Wpedantic -Werror)
    elseif(MSVC)
        target_compile_options(TorchCS-Logger PRIVATE /W4 /WX)
    endif()
endif()


if(TORCHCS_LOGGER_EXECUTABLE)
    message(STATUS "Building TorchCS-Logger as an executable")

    add_executable(TorchCS-Logger-Executable tests/main.cpp)

    target_include_directories(TorchCS-Logger-Executable PRIVATE include)
    target_link_libraries(TorchCS-Logger-Executable PRIVATE TorchCS-Logger spdlog::spdlog)

    if(TORCHCS_LOGGER_INSTALL)
        install(TARGETS TorchCS-Logger-Executable
            RUNTIME DESTINATION bin
        )
    endif()
endif()

if(TORCHCS_LOGGER_INSTALL)
    message(STATUS "Installing TorchCS-Logger")

    install(TARGETS TorchCS-Logger
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include
    )

    install(DIRECTORY include/ DESTINATION include)
endif()
