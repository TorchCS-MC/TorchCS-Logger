from conan.tools.cmake import cmake_layout, CMakeToolchain
from conan import ConanFile

class ConanApplication(ConanFile):
    name = "TorchCS-Logger"
    version = "1.0.0"
    author = "Reversed Codes"
    description = "TorchCS Logger is an extension of spdlog. It is generally used for console applications, such as bots or server software."
    settings = "os", "compiler", "build_type", "arch"



