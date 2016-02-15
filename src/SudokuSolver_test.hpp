/*
 * SudokuSolver_test.hpp
 *
 *  Created on: 12 Feb 2016
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKUSOLVER_TEST_HPP_
#define SRC_SUDOKUSOLVER_TEST_HPP_

#include "cute.h"
#include "Sudoku.hpp"

class SudokuSolver_test {
public:
	SudokuSolver_test();
    // Must define void operator() with no arguments.
    // In implementation: add calls to cute-assert functions and methods like someFunction1
    void operator()();
    static cute::suite make_suite();

private:
    void solverTest();
    void solverTest2();
    void performanceTest();
    void performanceTest2();
    void hexadokuSolverTest();
    void hexadokuPerformanceTest();
    void sudokuBatchSolveTest();
    void hexadokuBatchSolveTest();
    Sudoku sampleSudoku();
    Sudoku sampleSudoku2();
    Sudoku completeSudoku();
    Sudoku sampleHexadoku();
};

#endif /* SRC_SUDOKUSOLVER_TEST_HPP_ */
