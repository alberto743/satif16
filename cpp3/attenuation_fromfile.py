#!/usr/bin/env python3

from attenuation import Problem

p1 = Problem.load_input("data.txt")
p2 = Problem.load_input("data2.txt")

res1 = p1.solve()
res2 = p2.solve()

print(p1)
print("Result1: ", res1)
print()
print(p2)
print("Result2: ", res2)
