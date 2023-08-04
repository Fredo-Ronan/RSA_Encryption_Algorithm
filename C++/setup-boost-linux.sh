#!/bin/bash

wget "https://boostorg.jfrog.io/artifactory/main/release/1.82.0/source/boost_1_82_0.tar.gz"
tar -xf boost_1_82_0.tar.gz

cd boost_1_82_0
sudo cp boost /usr/include/c++/9

echo "Setup for 'boost' library complete!"
