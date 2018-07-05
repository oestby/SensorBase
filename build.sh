#!/bin/bash

let testing=false

while getopts "t" opt; do
    case "$opt" in
        t)  echo "Testing enabled"
            testing=true
            ;;
    esac
done

if ! [ -d build ]; then
    echo "Creating build directory..."
    mkdir build
fi

cd build
cmake ..
cmake --build . 

if [ "$testing" = true ] ; then
    export GTEST_COLOR=YES
    ctest -VV
fi;
