/*
 * Sudoku.cpp
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#include "Sudoku.h"

std::string Sudoku::toString()
{
	std::string string {"+-----------------------+\n"};
	for (int row = 0; row < 9; row++) {
		if (row != 0 && row%3 == 0)
			string += "|-------+-------+-------|\n";
		for (int col = 0; col < 9; col++) {
			if (col%3 == 0)
				string += "| ";
			string += std::to_string(cells[row][col]) + " ";
		}
		string += "|\n";
	}
	string += "+-----------------------+\n";
	return string;
}

bool Sudoku::isIncomplete() {
	for (const auto &row : cells) {
		for (const auto &val : row)
			if (val == 0) return true;
	}
	return false;
}

bool Sudoku::isComplete() {
	return !isIncomplete();
}

bool Sudoku::safeInRow(int row, int num) {
	for (const auto &val : cells[row]) {
		if (val == num) return false;
	}
	return true;
}

bool Sudoku::safeInCol(int col, int num) {
	for (const auto &row : cells) {
		if (row[col] == num) return false;
	}
	return true;
}

bool Sudoku::safeInSqr(int startRow, int startCol, int num) {
	int endRow { startRow + 3 },
		endCol { startCol + 3 };
	for (int i = startRow; i < endRow; i++)
		for (int j = startCol; j < endCol; j++)
			if (cells[i][j] == num) return false;
	return true;
}

bool Sudoku::isSafe(int row, int col, int num) {
	return (safeInRow(row, num) &&
			safeInCol(col, num) &&
			safeInSqr(row - row%3, col - col%3, num));
}

bool Sudoku::cellIsEmpty(int row, int col) {
	return cells[row][col] == 0;
}

bool Sudoku::isCorrect() {
	for (int i = 0; i < 9; i++) {
		if (!correctInRow(i) || !correctInCol(i)) return false;
	}
	for (int i = 0; i < 9; i+=3) {
		for (int j = 0; j < 9; j+=3) {
			if (!correctInSqr(i,j)) return false;
		}
	}
	return true;
}

bool Sudoku::correctInRow(int row) {
	for (int val = 1; val <= 9; val++)
		for (int i = 0; i < 9; i++) {
			int check_val = cells[row][i];
			if (check_val <= 0 || check_val > 9) return false;
			if (check_val == val) break;
		}
	return true;
}

bool Sudoku::correctInCol(int col) {
	for (int val = 1; val <= 9; val++)
		for (int i = 0; i < 9; i++) {
			int check_val = cells[i][col];
			if (check_val <= 0 || check_val > 9) return false;
			if (check_val == val) break;
		}
	return true;
}

bool Sudoku::correctInSqr(int startRow, int startCol) {
	int endRow { startRow + 3 },
		endCol { startCol + 3 };
	for (int i = startRow; i < endRow; i++)
		for (int j = startCol; j < endCol; j++){
			//TODO: incomplete check
		}
	return true;
}
