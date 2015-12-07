/*
 * SimpleSudokuSolver.cpp
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SIMPLESUDOKUSOLVER_CPP_
#define SRC_SIMPLESUDOKUSOLVER_CPP_

#include "SudokuSolver.h"

template<size_t N>
Sudoku<N> SudokuSolver<N>::getSolution() {
	solve(0,0);
	return m_puzzle;
}

template<size_t N>
void SudokuSolver<N>::solve(int row, int col) {
	// base case
	if (m_puzzle.isComplete() || row >= size) return;

	if (m_puzzle.cellIsEmpty(row, col)) {
		for (int i = 1; i <= size; i++) {
			if (m_puzzle.isSafe(row, col, i)) {
				m_puzzle.setCell(row,col, i);
				// solve next cell
				if (col >= size-1) solve(row+1, 0);
				else solve(row, col+1);
				//return if solve(ie complete)
				if (m_puzzle.isComplete()) return;
				else m_puzzle.setCell(row, col, 0);
			}
		}
	} else {
		// solver next cell
		if (col >= size-1) solve(row+1, 0);
		else solve(row, col+1);
	}
}

#endif /* SRC_SIMPLESUDOKUSOLVER_CPP_ */
