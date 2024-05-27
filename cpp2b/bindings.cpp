#include <pybind11/pybind11.h>
#include "attenuation.hpp"

namespace py = pybind11;


PYBIND11_MODULE(attenuation, m) {
    py::class_<Problem>(m, "Problem")
        .def(py::init<>())
        .def("load_input", &Problem::load_input)
        .def("run", &Problem::run);
}