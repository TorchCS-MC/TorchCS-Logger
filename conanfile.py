from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMakeToolchain, CMake, CMakeDeps

class TorchCSLoggerRecipe(ConanFile):
    name = "torchcs-logger"
    package_type = "library"
    version = "1.0.0"
    author = "Reversed Codes"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]} 
    default_options = {"shared": False}  

    exports_sources = "CMakeLists.txt", "src/*", "include/*", "tests/*"

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("spdlog/1.15.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()
