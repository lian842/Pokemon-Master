#!/bin/bash

# Ensure the build directory exists
mkdir -p build

# Compile the program with C++17, output to build/main
g++ -std=c++17 /Users/_lian_/Desktop/oop/main.cpp -o build/main

# Remove stray executables from src directory (cleanup)
rm -f src/main

# Run the program with input redirection
if [ -f "$1" ]; then
    ./build/main < "$1" > "$2"
else
    echo "Usage: ./run.sh input_file output_file"
fi
