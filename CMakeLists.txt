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

add_executable(${PROJECT_NAME}
        tests/main.cpp
        src/LoggerManager.cpp
        src/LoggerOptions.cpp
        src/CustomFormatter.cpp
        src/LogColor.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
target_include_directories(${PROJECT_NAME} PUBLIC include)


if(WIN32)
    message(STATUS "Configuring for Windows...")
    #target_link_libraries(${PROJECT_NAME} PRIVATE )
elseif(UNIX)
    message(STATUS "Configuring for Linux...")
    #target_link_libraries(${PROJECT_NAME} PRIVATE dl pthread)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(${PROJECT_NAME}  PRIVATE /W4)
endif()