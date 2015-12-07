/*
 * SimpleSudokuSolver.cpp
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#include "SudokuSolver.h"

Sudoku SudokuSolver::getSolution() {
	solve(0,0);
	return m_puzzle;
}

void SudokuSolver::solve(int row, int col) {
	// base case
	if (m_puzzle.isComplete() || row >= 9) return;

	if (m_puzzle.cellIsEmpty(row, col)) {
		for (int i = 1; i <= 9; i++) {
			if (m_puzzle.isSafe(row, col, i)) {
				m_puzzle.setCell(row,col, i);
				// solve next cell
				if (col >= 8) solve(row+1, 0);
				else solve(row, col+1);
				//return if solve(ie complete)
				if (m_puzzle.isComplete()) return;
				else m_puzzle.setCell(row, col, 0);
			}
		}
	} else {
		// solver next cell
		if (col >= 8) solve(row+1, 0);
		else solve(row, col+1);
	}
}
