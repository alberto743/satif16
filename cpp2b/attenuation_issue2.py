#!/usr/bin/env python3

import attenuation

p1 = attenuation.Problem()
p1.load_input("data.txt")

p2 = attenuation.Problem()
p2.load_input("data2.txt")

p1.run()
p2.run()
