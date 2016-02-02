/*
 * SudokuSolver.h
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKUSOLVER_HPP_
#define SRC_SUDOKUSOLVER_HPP_

#include "Sudoku.hpp"

class SudokuSolver
{
private:
	Sudoku m_puzzle;
	int m_size { };

	SudokuSolver() {} // private default constructor

public:
	SudokuSolver(Sudoku puzzle);
	SudokuSolver(int **const arr, int size);

	Sudoku getSolution();

private:
	void solve(int row, int col);
};

#endif /* SRC_SUDOKUSOLVER_HPP_ */
