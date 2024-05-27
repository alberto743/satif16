#!/bin/bash

g++ -g -o attenuation attenuation.cpp
g++ -g -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) attenuation.cpp bindings.cpp -o attenuation$(python3-config --extension-suffix)
