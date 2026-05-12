#!/usr/bin/env python3

# SPDX-FileCopyrightText: 2026 Alberto P
#
# SPDX-License-Identifier: MPL-2.0

import subprocess
import tempfile
from pathlib import Path
import argparse


def run_console(program, workdir, *args):
    console_result = subprocess.run(
        [program] + list(args),
        capture_output=True,
        text=True,
        check=True,
        cwd=workdir
    )

    return console_result.stdout, console_result.stderr, console_result.returncode


def solve_attenutation(executable, thick1, thick2, sigma1, sigma2, source):
    with tempfile.TemporaryDirectory() as tempdir:
        input_deck = Path(tempdir) / "data.txt"
        with open(input_deck, "w") as f:
            f.write(f"{thick1}\n{thick2}\n{sigma1}\n{sigma2}\n{source}\n")
        output, _, _ = run_console(executable, tempdir)

    intensity = float(output.strip())
    return intensity


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--executable", default=Path.cwd() / "attenuation")
    parser.add_argument("--thick1", type=float, default=3.1e-3)
    parser.add_argument("--thick2", type=float, default=6.82e-2)
    parser.add_argument("--sigma1", type=float, default=2.1)
    parser.add_argument("--sigma2", type=float, default=1.2)
    parser.add_argument("--source", type=float, default=57.33)

    args = parser.parse_args()

    intensity = solve_attenutation(
        args.executable,
        args.thick1,
        args.thick2,
        args.sigma1,
        args.sigma2,
        args.source
    )
    print(intensity)


if __name__ == "__main__":
    main()
