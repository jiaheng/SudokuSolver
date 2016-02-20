/*
 * SudokuSolver.h
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKUSOLVER_HPP_
#define SRC_SUDOKUSOLVER_HPP_

#include <atomic>
#include "Sudoku.hpp"

class SudokuSolver
{
private:
	Sudoku m_puzzle;
	int m_size { };
	std::atomic<bool> isSolve { false };
	std::atomic<unsigned> numThread { 0 };
	bool multithread { true };
	unsigned concurentThreadsSupported { 0 };

	SudokuSolver() {} // private default constructor

public:
	SudokuSolver(Sudoku puzzle);
	SudokuSolver(Sudoku puzzle, bool multi_thread);
	SudokuSolver(int **const arr, int size);

	Sudoku getSolution();
	Sudoku dlxGetSolution();

private:
	void solve();
	std::vector<std::vector <int>> toExactCover();
	std::vector<int> toExactCoverRow(int row, int col, int num);
	void rowToSudoku(std::vector<int> row);
	void fillSudoku(std::vector<std::vector <int>> matrix, std::vector<int> solution);
	void solve(int row, int col, Sudoku &puzzle);
	void newThreadSolve(int row, int col, Sudoku puzzle);
};

#endif /* SRC_SUDOKUSOLVER_HPP_ */
