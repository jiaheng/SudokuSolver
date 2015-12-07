/*
 * SudokuSolver.h
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKUSOLVER_H_
#define SRC_SUDOKUSOLVER_H_

#include "Sudoku.h"

template<size_t N>
class SudokuSolver
{
private:
	Sudoku<N> m_puzzle;
	int size = static_cast<int>(N);

	SudokuSolver() {} // private default constructor

public:
	SudokuSolver(Sudoku<N> puzzle) { m_puzzle = Sudoku<N>(puzzle); }
	SudokuSolver(std::array<int, N> const &arr) { m_puzzle = Sudoku<N>(arr); }

	Sudoku<N> getSolution();

private:
	void solve(int row, int col);
};

#include "SimpleSudokuSolver.cpp"

#endif /* SRC_SUDOKUSOLVER_H_ */
