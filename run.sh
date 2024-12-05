#!/bin/bash

# Stop on error or undefined variable
set -eu

# Usage function for clarity
usage() {
    echo "Usage: $0 input_file output_file"
    exit 1
}

# Check if correct number of arguments is provided
if [ $# -ne 2 ]; then
    usage
fi

# Variables for input, output, and compilation paths
INPUT_FILE="$1"
OUTPUT_FILE="$2"
BUILD_DIR="./build"
EXECUTABLE="$BUILD_DIR/main"
SOURCE_FILE="/Users/_lian_/Desktop/oop/src/main.cpp"

# Ensure the build directory exists
mkdir -p "$BUILD_DIR"

# Check if the input file exists
if [ ! -f "$INPUT_FILE" ]; then
    echo "Error: Input file '$INPUT_FILE' not found."
    exit 1
fi

# Compile the C++ program with C++17 standard
echo "Compiling the program..."
if ! g++ -std=c++17 "$SOURCE_FILE" -o "$EXECUTABLE"; then
    echo "Error: Compilation failed. Please check your source code."
    exit 1
fi
echo "Compilation successful."

# Execute the compiled program with input and output redirection
echo "Executing the program..."
if "$EXECUTABLE" < "$INPUT_FILE" > "$OUTPUT_FILE"; then
    echo "Execution successful. Output written to '$OUTPUT_FILE'."
else
    echo "Error: Program execution failed."
    exit 1
fi

