#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "attenuation.hpp"

namespace py = pybind11;


PYBIND11_MODULE(attenuation, m) {
    py::class_<Material, std::shared_ptr<Material>>(m, "Material")
        .def(py::init<const double&>())
        .def_property_readonly("sigma", &Material::get_sigma)
        .def("__repr__", &Material::show)
        ;

    py::class_<Slab, std::shared_ptr<Slab>>(m, "Slab")
        .def(py::init<const double&, const std::shared_ptr<Material>&>())
        .def_property_readonly("thickness", &Slab::get_thickness)
        .def_property_readonly("material", &Slab::get_material)
        .def("__repr__", &Slab::show)
        ;

    py::class_<Problem, std::shared_ptr<Problem>>(m, "Problem")
        .def(py::init<const double&, const std::vector<Slab>&>())
        .def_static("load_input", &Problem::load_input)
        .def_property("source", &Problem::get_source, &Problem::set_source)
        .def_property_readonly("slabs", &Problem::get_slabs)
        .def("solve", &Problem::solve)
        .def("__repr__", &Problem::show)
        ;
}