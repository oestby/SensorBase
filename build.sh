#!/bin/bash

if ! [ -d build ]; then
    echo "Creating build directory..."
    mkdir build
fi

cd build
cmake ..
export GTEST_COLOR=YES
cmake --build . && ctest -VV
