#!/bin/bash

# Compile the C++ program
g++ -std=c++11 main.cpp -o main

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled program
    ./my_program
else
    echo "Compilation failed. Please check your C++ code."
fi
