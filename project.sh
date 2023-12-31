#!/usr/bin/bash
BASEDIR=$(dirname "$0")
pushd "$BASEDIR"

rm -rf build
set -e
conan install . --output-folder=build --build=missing
pushd ./build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
time cmake --build .
popd
