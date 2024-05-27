#!/usr/bin/env python3

from attenuation import Material, Slab, Problem

m1 = Material(3.1e-3)
m2 = Material(6.82e-2)
s1 = Slab(2.1, m1)
s2 = Slab(1.2, m2)

p = Problem(57.33, (s1, s2))
res = p.solve()

print(p)
print("Result: ", res)
