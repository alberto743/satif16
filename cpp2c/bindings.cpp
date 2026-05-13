// SPDX-FileCopyrightText: Copyright © 2026 Alberto P
//
// SPDX-License-Identifier: MPL-2.0

#include <pybind11/pybind11.h>
#include "attenuation.hpp"

namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<Layer>);
PYBIND11_MAKE_OPAQUE(std::vector<Element>);


PYBIND11_MODULE(attenuation, m) {
    py::class_<Layer>(m, "Layer")
        .def(py::init<double>())
        .def("set_thick", &Layer::set_thick)
        .def("get_thick", &Layer::get_thick);

    py::class_<Element>(m, "Element")
        .def(py::init<double>())
        .def("set_sigma", &Element::set_sigma)
        .def("get_sigma", &Element::get_sigma);

    m.def("get_material", [](size_t index) -> Element& {
        if (index >= materials.size()) throw py::index_error();
        return materials[index];
    }, py::return_value_policy::reference_internal);

    m.def("get_layer", [](size_t index) -> Layer& {
        if (index >= geometry.size()) throw py::index_error();
        return geometry[index];
    }, py::return_value_policy::reference_internal);

    m.def("get_source", []() { return source; });
    m.def("set_source", [](double v) { source = v; });

    py::class_<Problem>(m, "Problem")
        .def(py::init<>())
        .def("load_input", &Problem::load_input)
        .def("run", &Problem::run)
        .def("get_intensity", &Problem::get_intensity);
}
