/*
 * SudokuSolver.h
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKUSOLVER_H_
#define SRC_SUDOKUSOLVER_H_

#include <atomic>
#include "Sudoku.h"

template<size_t N>
class SudokuSolver
{
private:
	Sudoku<N> m_puzzle;
	int size = static_cast<int>(N);
	std::atomic<bool> isSolve { false };
	std::atomic<int> numThread { 0 };

	SudokuSolver() {} // private default constructor

public:
	SudokuSolver(Sudoku<N> puzzle) { m_puzzle = Sudoku<N>(puzzle); }
	SudokuSolver(std::array<int, N> const &arr) { m_puzzle = Sudoku<N>(arr); }

	Sudoku<N> getSolution();

private:
	void solve(int row, int col, Sudoku<N>& puzzle);
	void newThreadSolve(int row, int col, Sudoku<N> puzzle);
};

#include "SudokuSolver.cpp"

#endif /* SRC_SUDOKUSOLVER_H_ */
