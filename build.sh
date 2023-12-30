#!/usr/bin/bash
rm -rf build
mkdir build
set -e
pushd ./build
cmake ..
time make
popd
