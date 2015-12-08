/*
 * Copyright (c) 2015 Jia Heng Eik
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

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
