# Puzzle utilities
![status](https://raw.githubusercontent.com/thomashoullier/badges/master/status-maintained.svg)
![stage](https://raw.githubusercontent.com/thomashoullier/badges/master/stage-alpha.svg)

[![Build Status](https://drone.git-or-miss.com/api/badges/thomashoullier/puzzle_utils/status.svg)](https://drone.git-or-miss.com/thomashoullier/puzzle_utils)
[![codecov](https://codecov.io/gh/thomashoullier/puzzle_utils/graph/badge.svg?token=T2E1C7N6IL)](https://codecov.io/gh/thomashoullier/puzzle_utils)

`puzzle_utils` is a C++ library implementing utilities for solving programming
puzzles such as the ones found in project Euler.

This is mostly a personal library for playing around with modern C++ features.

## Documentation
The following documentation is available:
* A doxygen documentation is here: https://thomashoullier.github.io/puzzle_utils/
* A latex documentation covering this library and related standard C++ libraries
  is in progress.

## Build and run examples
Identify in `examples/` you want to run, eg. `ex_iota`.
Switch to the `build/` directory.
Run the following,

```shell
cmake -Dpzu_build_examples=ON ..
make ex_iota
./ex_iota
```
