#!/usr/bin/env python3

# SPDX-FileCopyrightText: Copyright © 2024 Alberto P
#
# SPDX-License-Identifier: MPL-2.0

import math

inputdata = "data.txt"

with open(inputdata, 'r') as fin:
     sigma1, sigma2, thick1, thick2, intensity0 = [float(v) for v in fin.read().splitlines()]

intensity = intensity0 * math.exp(- (sigma1*thick1 + sigma2*thick2))

#print(sigma1, sigma2, thick1, thick2, intensity0)
print(intensity)
