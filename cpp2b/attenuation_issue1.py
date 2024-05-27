#!/usr/bin/env python3

import attenuation

p = attenuation.Problem()
p.load_input("data.txt")
res = p.run()

print(res)
