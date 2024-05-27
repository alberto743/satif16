#!/bin/bash

g++ -g -o attenuation2 attenuation2.cpp
g++ -g -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) attenuation2.cpp bindings.cpp -o attenuation$(python3-config --extension-suffix)
