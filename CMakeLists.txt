# SPDX-FileCopyrightText: 2026 Alberto P
#
# SPDX-License-Identifier: MPL-2.0

cmake_minimum_required(VERSION 3.10)
project(Attenuation)

include(ExternalProject)
include(GNUInstallDirs)


set(fortran1_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/fortran1")
ExternalProject_Add(
    fortran1
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/fortran1
    BINARY_DIR ${fortran1_BINARY_DIR}
    INSTALL_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_BINDIR=${CMAKE_INSTALL_BINDIR}
        -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}
)
install(CODE "
    execute_process(
        COMMAND \${CMAKE_COMMAND} --install \"${fortran1_BINARY_DIR}\" --prefix \"\${CMAKE_INSTALL_PREFIX}/fortran1\"
        COMMAND_ERROR_IS_FATAL ANY
    )
")

set(fortran2_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/fortran2")
ExternalProject_Add(
    fortran2
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/fortran2
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/fortran2
    INSTALL_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_BINDIR=${CMAKE_INSTALL_BINDIR}
        -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}
)
install(CODE "
    execute_process(
        COMMAND \${CMAKE_COMMAND} --install \"${fortran2_BINARY_DIR}\" --prefix \"\${CMAKE_INSTALL_PREFIX}/fortran2\"
        COMMAND_ERROR_IS_FATAL ANY
    )
")

set(cpp2_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpp2")
ExternalProject_Add(
    cpp2
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpp2
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/cpp2
    INSTALL_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_BINDIR=${CMAKE_INSTALL_BINDIR}
        -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}
)
install(CODE "
    execute_process(
        COMMAND \${CMAKE_COMMAND} --install \"${cpp2_BINARY_DIR}\" --prefix \"\${CMAKE_INSTALL_PREFIX}/cpp2\"
        COMMAND_ERROR_IS_FATAL ANY
    )
")

set(cpp2a_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpp2a")
ExternalProject_Add(
    cpp2a
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpp2a
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/cpp2a
    INSTALL_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_BINDIR=${CMAKE_INSTALL_BINDIR}
        -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}
)
install(CODE "
    execute_process(
        COMMAND \${CMAKE_COMMAND} --install \"${cpp2a_BINARY_DIR}\" --prefix \"\${CMAKE_INSTALL_PREFIX}/cpp2a\"
        COMMAND_ERROR_IS_FATAL ANY
    )
")

set(cpp2b_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpp2b")
ExternalProject_Add(
    cpp2b
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpp2b
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/cpp2b
    INSTALL_COMMAND ""
)
install(CODE "
    execute_process(
        COMMAND \${CMAKE_COMMAND} --install \"${cpp2b_BINARY_DIR}\" --prefix \"\${CMAKE_INSTALL_PREFIX}/cpp2b\"
        COMMAND_ERROR_IS_FATAL ANY
    )
")

set(cpp2c_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpp2c")
ExternalProject_Add(
    cpp2c
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpp2c
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/cpp2c
    INSTALL_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_BINDIR=${CMAKE_INSTALL_BINDIR}
        -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}
)
install(CODE "
    execute_process(
        COMMAND \${CMAKE_COMMAND} --install \"${cpp2c_BINARY_DIR}\" --prefix \"\${CMAKE_INSTALL_PREFIX}/cpp2c\"
        COMMAND_ERROR_IS_FATAL ANY
    )
")

set(cpp3_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpp3")
ExternalProject_Add(
    cpp3
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpp3
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/cpp3
    INSTALL_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_BINDIR=${CMAKE_INSTALL_BINDIR}
        -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}
)
install(CODE "
    execute_process(
        COMMAND \${CMAKE_COMMAND} --install \"${cpp3_BINARY_DIR}\" --prefix \"\${CMAKE_INSTALL_PREFIX}/cpp3\"
        COMMAND_ERROR_IS_FATAL ANY
    )
")


file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/CTestTestfile.cmake"
     "subdirs(\"${CMAKE_CURRENT_BINARY_DIR}/fortran1\"
              \"${CMAKE_CURRENT_BINARY_DIR}/fortran2\"
              \"${CMAKE_CURRENT_BINARY_DIR}/cpp2\"
              \"${CMAKE_CURRENT_BINARY_DIR}/cpp2a\"
              \"${CMAKE_CURRENT_BINARY_DIR}/cpp2b\"
              \"${CMAKE_CURRENT_BINARY_DIR}/cpp2c\"
              \"${CMAKE_CURRENT_BINARY_DIR}/cpp3\"
             )\n")
