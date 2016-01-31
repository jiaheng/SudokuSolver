/*
 * SudokuSolver.h
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKUSOLVER_HPP_
#define SRC_SUDOKUSOLVER_HPP_

#include "Sudoku.hpp"

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

#include "SudokuSolver.cpp"

#endif /* SRC_SUDOKUSOLVER_HPP_ */
