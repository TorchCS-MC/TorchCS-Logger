# TorchCS Logger

---

## Description

TorchCS Logger is an extension of spdlog. It is generally used for console applications, such as bots or server software

---
## Required Tools

- **CMake 3.20+** (recommended)
- **A C++20 compiler:**
  - **Windows:** MSVC (Visual Studio 2022) or MinGW
  - **Linux:** GCC 11+ or Clang 14+

---
## Installation of Dependencies

---
### Build

- Windows
    ```sh
    scripts/build_cmake.bat
    ```
- Linux 
    ```sh
    scripts/build_cmake.sh
    ```

---
## Your Project

- CMake
   - `CMakeLists.txt`
     **Code:**
     ```cmake
     find_package(torchcs-logger CONFIG REQUIRED)
     target_link_libraries(${PROJECT_NAME} PRIVATE torchcs-logger::torchcs-logger)
     target_link_libraries(${PROJECT_NAME} PRIVATE TorchCS-Logger.lib)
     ```



---
## License
This project is licensed under the **MIT License**.  
See the [LICENSE](LICENSE) file for more details.