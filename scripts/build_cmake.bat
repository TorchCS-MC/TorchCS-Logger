@echo off
cd ..
conan install . --build=missing
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE="generators/conan_toolchain.cmake"