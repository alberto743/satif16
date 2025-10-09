#!/usr/bin/env python3

# SPDX-FileCopyrightText: Copyright © 2024 Alberto P
#
# SPDX-License-Identifier: MPL-2.0

import attenuation

p = attenuation.Problem()
p.load_input("data.txt")
p.run()
