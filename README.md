# Sudoku Solver #

[![Build Status](https://travis-ci.org/jiaheng/SudokuSolver.svg?branch=master)](https://travis-ci.org/jiaheng/SudokuSolver)
[![Build status](https://ci.appveyor.com/api/projects/status/fqhlhw89d6a4uqq6?svg=true)](https://ci.appveyor.com/project/jiaheng/sudokusolver)
[![codecov](https://codecov.io/gh/jiaheng/SudokuSolver/branch/master/graph/badge.svg)](https://codecov.io/gh/jiaheng/SudokuSolver)

**SudokuSolver** is a program to solve sudoku puzzle. It can solve various type of sudoku:

* 4x4 sudoku
* Sudoku (9x9 sudoku puzzle)
* Hexadoku (16x16 sudoku puzzle)
* Alphadoku (25x25 sudoku puzzle)

## Getting Started

The following example [single_puzzle](./sample/single_puzzle) is a sample 9x9 sudoku puzzle, its content represent the puzzle as follows.

```
+-----------------------+
| 2 X 4 | X X X | 8 X X |
| X X X | 3 X 4 | X X X |
| X X X | X X X | X X X |
|-------+-------+-------|
| X 3 X | 5 X 7 | X X X |
| 6 X X | X X X | 4 X 2 |
| X X X | 1 X X | X X X |
|-------+-------+-------|
| X 1 X | X X X | X 5 X |
| 8 X X | X 9 X | X X X |
| X X X | X 6 X | X 7 X |
+-----------------------+
```

### Prerequisites

To use SusokuSolver, you need:
+ a C++11 compiler (GNU C++ Compiler G++ v4.8 or Clang 3.7 C++ Compiler)
+ CMake with version at least 3.10 or higher:

### Compile and run the program

Compile and run the program with the following commands:

```bash
~$ mkdir build    # create a build folder in the root directory
~$ cd build
~$ cmake ..
~$ make
~$ ./main/SudokuSolverApp ../sample/single_puzzle
```

Alternatively, you can output the solutions into a file.

```bash
# in build folder
~$ ./main/SudokuSolverApp ../sample/single_puzzle -o ./solution # add -v for verbose mode
```

## Running the tests

SudokuSolver uses [Google Test](https://github.com/google/googletest) for unit tests and CMake's testing framework to run the tests.

```bash
~$ mkdir build
~$ cd build
~$ cmake -DBUILD_TESTS=ON ..
~$ make
~$ make test
```

### Code coverage

SudokuSolver use [gcov](https://gcc.gnu.org/onlinedocs/gcc-4.8.5/gcc/Gcov.html) along with [lcov](https://github.com/linux-test-project/lcov) to test code coverage.

```bash
~$ mkdir build
~$ cd build
~$ cmake -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Coverage ..
~$ make
~$ make SudokuSolver_coverage
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
