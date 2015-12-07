/*
 * SudokuSolver.h
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKUSOLVER_H_
#define SRC_SUDOKUSOLVER_H_

#include "Sudoku.h"

class SudokuSolver
{
private:
	Sudoku m_puzzle;

	SudokuSolver() {} // private default constructor

public:
	SudokuSolver(Sudoku puzzle) { m_puzzle = Sudoku(puzzle); }
	template<typename T, size_t N>
	SudokuSolver(std::array<T, N> const &arr) { m_puzzle = Sudoku(arr); }

	Sudoku getSolution();

private:
	void solve(int row, int col);
};

#endif /* SRC_SUDOKUSOLVER_H_ */
