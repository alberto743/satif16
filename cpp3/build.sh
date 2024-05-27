#!/bin/bash

g++ -g -o attenuation3 attenuation3.cpp
g++ -g -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) attenuation3.cpp bindings.cpp -o attenuation$(python3-config --extension-suffix)
