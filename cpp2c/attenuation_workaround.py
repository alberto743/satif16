#!/usr/bin/env python3

# SPDX-FileCopyrightText: Copyright © 2024 Alberto P
#
# SPDX-License-Identifier: MPL-2.0

from multiprocessing import Pool


def info_ps(title):
    import os
    print(f">> {title}: pid {os.getpid()}, parent {os.getppid()}")


def solve_attenuation(sigma1, sigma2, thick1, thick2, source):
    import attenuation
    info_ps('solve_attenuation')

    prob = attenuation.Problem()

    materials = [attenuation.get_material(i) for i in range(2)]
    geometry = [attenuation.get_layer(i) for i in range(2)]

    materials[0].set_sigma(sigma1)
    materials[1].set_sigma(sigma2)
    geometry[0].set_thick(thick1)
    geometry[1].set_thick(thick2)
    attenuation.set_source(source)

    prob.run()

    result = prob.get_intensity()

    return result


def main():
    info_ps('main')

    sigma1 = 2.1
    sigma2 = 1.2
    thick1 = 3.1e-3
    thick2 = 6.82e-2
    source1 = 57.33
    source2 = 978.33

    with Pool(processes=1) as pool:
        result1 = pool.apply(
            solve_attenuation,
            args=(sigma1, sigma2, thick1, thick2, source1)
        )
    with Pool(processes=1) as pool:
        result2 = pool.apply(
            solve_attenuation,
            args=(sigma1, sigma2, thick1, thick2, source2)
        )

    print('Result for source1:', result1)
    print('Result for source2:', result2)


if __name__ == '__main__':
    main()
