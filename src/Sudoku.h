/*
 * Sudoku.h
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKU_H_
#define SRC_SUDOKU_H_

#include <array>
#include <string>

template<size_t N>
class Sudoku
{
private:
	std::array<std::array<int, N>, N> cells {};
	int size = static_cast<int>(N);

public:
	Sudoku() {}
	Sudoku(std::array<std::array<int,N>,N> const &arr);

	std::string toString();
	bool isSafe(int row, int col, int num);
	bool isIncomplete();
	bool isComplete();
	bool isCorrect();
	bool cellIsEmpty(int row, int col);

	void setCell(int row, int col, int val) { cells[row][col] = val; }

	int getCell(int row, int col){ return cells[row][col]; }

	friend bool operator==(Sudoku &cSudoku1, Sudoku &cSudoku2) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (cSudoku1.cells[i][j] != cSudoku2.cells[i][j]) return false;
		return true;
	}

private:
	bool safeInRow(int row, int num);
	bool safeInCol(int col, int num);
	bool safeInSqr(int startRow, int startCol, int num);
	bool correctInRow(int row);
	bool correctInCol(int col);
	bool correctInSqr(int startRow, int StartCol);
};

#include "Sudoku.cpp"

#endif /* SRC_SUDOKU_H_ */
