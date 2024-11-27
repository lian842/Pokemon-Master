#!/bin/bash

# Ensure the build directory exists
mkdir -p build

# Compile the program, output to build/main
g++ src/main.cpp -o build/main

# Remove stray executables from src directory (cleanup)
rm -f src/main

# Run the program
./build/main