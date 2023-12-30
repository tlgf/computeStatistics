#!/usr/bin/bash
rm -rf build
mkdir build
set -e
pushd ./build
#cmake -DCMAKE_INCLUDE_PATH=/home/tom/prog/_libs/include/boost/ -DBoost_NO_BOOST_CMAKE=TRUE -DBOOST_ROOT=/home/tom/prog/_libs/ ..
cmake -DBoost_NO_BOOST_CMAKE=TRUE -DBOOST_ROOT=/home/tom/prog/_libs/ ..
time make VERBOSE=1
popd
