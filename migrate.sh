#!/bin/bash

# Create a CMakeLists.txt file in the root of your project directory
touch CMakeLists.txt

# Get the list of source files in your Gradle project
src_files=$(find app/src/main/cpp -name "*.cpp")
header_files=$(find app/src/main/headers -name "*.h")

# Write the basic CMakeLists.txt file
echo "cmake_minimum_required(VERSION 3.10)" >> CMakeLists.txt
echo "project(MyProject)" >> CMakeLists.txt
echo "include_directories(app/src/main/headers)" >> CMakeLists.txt
echo "add_executable(MyProject \\" >> CMakeLists.txt
for file in $src_files; do
  echo "  $file \\" >> CMakeLists.txt
done
echo ")" >> CMakeLists.txt

# Run CMake to generate build files for your platform
mkdir build
cd build
cmake ..

