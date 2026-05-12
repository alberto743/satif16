# SPDX-FileCopyrightText: 2026 Alberto P
#
# SPDX-License-Identifier: MPL-2.0

cmake_minimum_required(VERSION 3.10)
project(attenuation
    VERSION 1.0.0
    LANGUAGES CXX
)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

include(GNUInstallDirs)
enable_testing()

add_executable(attenuation_exe
    attenuation.cpp
)
set_target_properties(attenuation_exe PROPERTIES
    OUTPUT_NAME "attenuation"
)

pybind11_add_module(attenuation_py
    bindings.cpp
    attenuation.cpp
)
set_target_properties(attenuation_py PROPERTIES
    OUTPUT_NAME "attenuation"
)


install(TARGETS attenuation_exe
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(TARGETS attenuation_py
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)


set(TEST_RUN_DIR "${CMAKE_CURRENT_BINARY_DIR}/test_attenuation_env")
file(MAKE_DIRECTORY "${TEST_RUN_DIR}")
add_test(NAME setup_test_attenuation
    COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/data.txt"
        "${TEST_RUN_DIR}"
)
add_test(NAME test_attenuation
    COMMAND attenuation_exe
    WORKING_DIRECTORY "${TEST_RUN_DIR}"
)


find_package(Python REQUIRED COMPONENTS Interpreter)
set(MODULE_OUTPUT_DIR $<TARGET_FILE_DIR:attenuation_py>)

add_test(NAME test_attenuation_py_base
    COMMAND Python::Interpreter ${CMAKE_CURRENT_SOURCE_DIR}/attenuation_base.py
)
set_tests_properties(test_attenuation_py_base PROPERTIES
    ENVIRONMENT "PYTHONPATH=${MODULE_OUTPUT_DIR}"
    WORKING_DIRECTORY "${TEST_RUN_DIR}"
)

add_test(NAME test_attenuation_py_module
    COMMAND Python::Interpreter ${CMAKE_CURRENT_SOURCE_DIR}/attenuation_module.py
)
set_tests_properties(test_attenuation_py_module PROPERTIES
    ENVIRONMENT "PYTHONPATH=${MODULE_OUTPUT_DIR}"
    WORKING_DIRECTORY "${TEST_RUN_DIR}"
)
