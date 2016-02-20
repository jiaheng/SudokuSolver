/*
 * SudokuSolver.h
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKUSOLVER_HPP_
#define SRC_SUDOKUSOLVER_HPP_

#include "Sudoku.hpp"

class SudokuSolver
{
private:
	Sudoku m_puzzle;
	int m_size { };

	SudokuSolver() {} // private default constructor

public:
	SudokuSolver(Sudoku puzzle);
	SudokuSolver(int **const arr, int size);
	Sudoku getSolution();

private:
	void solve();
	std::vector<std::vector <int>> toExactCover();
	std::vector<int> toExactCoverRow(int row, int col, int num);
	void rowToSudoku(std::vector<int> row);
	void fillSudoku(std::vector<std::vector <int>> matrix, std::vector<int> solution);
};

#endif /* SRC_SUDOKUSOLVER_HPP_ */
