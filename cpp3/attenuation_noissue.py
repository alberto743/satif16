#!/usr/bin/env python3

from attenuation import Material, Slab, Problem

m1 = Material(3.1e-3)
m2 = Material(6.82e-2)
s1 = Slab(2.1, m1)
s2 = Slab(1.2, m2)

p1 = Problem(57.33, (s1, s2))
p2 = Problem(978.33, p1.slabs)
res1 = p1.solve()
res2 = p2.solve()

print(p1)
print("Result1: ", res1)
print()
print(p2)
print("Result2: ", res2)
