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

#include <thread>
#include <iostream>
#include <vector>

#include "SudokuSolver.hpp"

SudokuSolver::SudokuSolver(Sudoku puzzle) {
	m_puzzle = Sudoku(puzzle);
	m_size = m_puzzle.getSize();
}

SudokuSolver::SudokuSolver(int **const arr, int m_size) {
	m_puzzle = Sudoku(arr, m_size);
	m_size = m_puzzle.getSize();
}

Sudoku SudokuSolver::getSolution() {
	std::thread t1(&SudokuSolver::newThreadSolve, this, 0, 0, m_puzzle);
	t1.join();
	return m_puzzle;
}

void SudokuSolver::solve(int row, int col, Sudoku &puzzle) {
	// base case
	if (row >= m_size) {
		isSolve = puzzle.isCorrect();
		m_puzzle = Sudoku(puzzle);
		return;
	}

	// exit when solved
	if (isSolve) return;

	int nextRow { row }, nextCol { col };
	if (col >= m_size-1) {
		nextRow++;
		nextCol = 0;
	} else
		nextCol++;

	if (puzzle.cellIsEmpty(row, col)) {
		std::vector<std::thread> threads { };
		for (int i = 1; i <= m_size; i++) {
			if (puzzle.isSafe(row, col, i)) {
				puzzle.setCell(row,col, i);
				if (numThread < 8) {
					// create new thread to solve
					threads.push_back(std::thread(&SudokuSolver::newThreadSolve, this, nextRow, nextCol, puzzle));
				} else {
					solve(nextRow, nextCol, puzzle);
					if (isSolve) {
						// wait all thread to finish
						for(auto& thread : threads){
							thread.join();
						}
						return;
					}
				}
				puzzle.setCell(row, col, 0);
			}
		}
		// wait all thread to finish
		for(auto& thread : threads){
			thread.join();
		}
	} else {
		solve(nextRow, nextCol, puzzle);
	}
}

void SudokuSolver::newThreadSolve(int row, int col, Sudoku puzzle) {
	numThread++;
	solve(row, col, puzzle);
	numThread--;
}
