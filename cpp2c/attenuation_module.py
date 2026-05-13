#!/usr/bin/env python3

# SPDX-FileCopyrightText: Copyright © 2026 Alberto P
#
# SPDX-License-Identifier: MPL-2.0

import attenuation


p = attenuation.Problem()

materials = [attenuation.get_material(i) for i in range(2)]
geometry = [attenuation.get_layer(i) for i in range(2)]

materials[0].set_sigma(3.1e-3)
materials[1].set_sigma(6.82e-2)
geometry[0].set_thick(2.1)
geometry[1].set_thick(1.2)
attenuation.set_source(57.33)

p.run()

result = p.get_intensity()

print("Result: ", result)
