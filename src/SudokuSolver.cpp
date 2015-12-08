/*
 * SimpleSudokuSolver.cpp
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SIMPLESUDOKUSOLVER_CPP_
#define SRC_SIMPLESUDOKUSOLVER_CPP_

#include "SudokuSolver.h"
#include <thread>
#include <iostream>
#include <vector>

template<size_t N>
Sudoku<N> SudokuSolver<N>::getSolution() {
	std::thread t1(&SudokuSolver::newThreadSolve, this, 0, 0, m_puzzle);
	t1.join();
	return m_puzzle;
}

template<size_t N>
void SudokuSolver<N>::solve(int row, int col, Sudoku<N>& puzzle) {
	// base case
	if (row >= size) {
		isSolve = puzzle.isCorrect();
		m_puzzle = Sudoku<N>(puzzle);
		return;
	}

	// exit when solved
	if (isSolve) return;

	int nextRow { row }, nextCol { col };
	if (col >= size-1) {
		nextRow++;
		nextCol = 0;
	} else
		nextCol++;

	if (puzzle.cellIsEmpty(row, col)) {
		std::vector<std::thread> threads { };
		for (int i = 1; i <= size; i++) {
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

template<size_t N>
void SudokuSolver<N>::newThreadSolve(int row, int col, Sudoku<N> puzzle) {
	numThread++;
	solve(row, col, puzzle);
	numThread--;
}

#endif /* SRC_SIMPLESUDOKUSOLVER_CPP_ */
