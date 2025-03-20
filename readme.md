# TorchCS Logger

---

## Description

TorchCS Logger is an extension of spdlog. It is generally used for console applications, such as bots or server software

---
## Required Tools

- **Python 3.8+** (for Conan)
- **CMake 3.20+** (recommended)
- **A C++20 compiler:**
  - **Windows:** MSVC (Visual Studio 2022) or MinGW
  - **Linux:** GCC 11+ or Clang 14+
- **Conan Package Manager**

---
## Installation of Dependencies

1. **Download & Install Python**:  
   - [Python Official Download](https://www.python.org/downloads/)  
   - Ensure Python is added to the system `PATH` during installation.

2. **Install Conan** using `pip`:  
   ```sh
   pip install conan
   ```

3. **Verify Conan Installation**:  
   ```sh
   conan --version
   ```
---
### Build

- Windows
    ```sh
    scripts/build_cmake.bat
    ```
    ```sh
    scripts/build_local_conan.bat
    ```
- Linux 
    ```sh
    scripts/build_cmake.sh
    ```
    ```sh
    scripts/build_local_conan.sh
    ```

---
## License
This project is licensed under the **MIT License**.  
See the [LICENSE](LICENSE) file for more details.