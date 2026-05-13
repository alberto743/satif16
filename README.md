<!--
SPDX-FileCopyrightText: Copyright © 2024-2026 Alberto P

SPDX-License-Identifier: MPL-2.0
-->

# Purpose
The purpose of this repository is to provide different implementations of the 2-slab attenuation problem, showing the effects of software design choices of the compiled language part to the bindings and the states available in the high-level user interface.

## SATIF-16
This work has been firstly presented at [SATIF-16](https://agenda.infn.it/event/34704/).
Further extentions have been added over time.

# Description

## python
This is a basic implementation of the 2-slab attenuation in Python by simple application of the
$I = I_0 \cdot e^{- (\Sigma_1 d_1 + \Sigma_2 d_2)}$ equation.

## fortran1
This implementaion in Fortran is based on the idea of reading the input parameters from a card-based input deck.
The output is provided in the standard output.

## fortran2
Like [fortran1](#fortran1), but exposing the typical building blocks of the processing in terms of parsing of the card-based input deck and call of the numerical solver.

## cpp2
This is a C++ version derived from [fortran2](#fortran2) in which the basic idea is to simply translate the calculation tool into a more modern programming language to enhance its capabilities.
The parsing of the card-based input deck and the output shown into the standard output are preserved with the idea to keep retrocompatibility.

## cpp2a
This is an attempt to provide a Python interface to the [cpp2](#cpp2) version.
The goal is to go beyond the concept of the card-based input and results into the standard output to provide a more friendly user interface.
Because of the fact that the C++ code incorporates the data inside its internal state, the approach provided is to wrap around the original executable by providing some supporting functions that take care of preparing the input and parsing the output.
Since the original executable needs to read and write from the disk, the processing is performed in a dedicated temporary directory.

## cpp2b
This version follows the same goal of [cpp2a](#cpp2a), but it uses a different approach to wrap around the original executable.
Instead, it provides [pybind11](https://github.com/pybind/pybind11) bindings of the C++ objects, that can be used directly in Python.
Because of the presence of the internal state inside the oridinal C++ code, this approach results in several unintuitive behaviors, especially when multiple problems exist in the same Python interpreter.
Indeed, the processing in Python still requires the existence of an input deck on disk.

## cpp2c
This version tries to tackle the issues of [cpp2b](#cpp2b) by adding additional Python bindings to modify the internal state of the C++ code for the purpose of having a more flexible interface.
While these accessors let the user manipulate the variables directly without relying on disk files, the standard output is still polluted by the output from the original executable and it is by default not possible to run more than problem in the same Python interpreter.
The workaround proposed tackle the latter issue by exploiting a process-based parallelism that let each solution run in a separate Python interpreter.

## cpp3
This is a completly revamped version in which the C++ version is made of reentrant routines free of any internal state.
In this case, the Python bindings assure to manage the variables characterizing the problem from the user space, to attain a natural and more effective user interface.


# Licensing
This project is [REUSE compliant](https://reuse.software/) and is licensed under the **Mozilla Public License 2.0 (MPL-2.0)**.
This allows for the integration of thes routine into larger works (including proprietary or restricted software) without affecting the license of the larger work, provided that the MPL-2.0-licensed source files remain under the MPL-2.0.
