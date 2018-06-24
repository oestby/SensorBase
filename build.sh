#!/bin/bash

cd include/serial
make ext
cd ../..

if ! [ -d build ]; then
    echo "Creating build directory..."
    mkdir build
fi

cd build
cmake ..
make
