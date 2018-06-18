/*
 * Sudoku.hpp
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKU_HPP_
#define SRC_SUDOKU_HPP_

#include <iostream>
#include <string>

class Sudoku {
private:
	int** cells { NULL };
	int size;

public:
	Sudoku(int **const arr, int size);
	Sudoku(std::string input);
	Sudoku(const Sudoku &other);
	~Sudoku();

	std::string toString();
	std::string toSimpleString();
	bool isSafe(int row, int col, int num);
	bool isIncomplete();
	bool isComplete();
	bool isCorrect();
	bool cellIsEmpty(int row, int col);

	int getSize();
	void setCell(int row, int col, int val);
	int getCell(int row, int col);
	Sudoku& operator=(const Sudoku &rhs);
	bool operator==(Sudoku &rhs);
	friend std::ostream& operator<<(std::ostream &os, Sudoku &sudoku);

private:
	bool safeInRow(int row, int num);
	bool safeInCol(int col, int num);
	bool safeInSqr(int startRow, int startCol, int num);
	bool correctInRow(int row);
	bool correctInCol(int col);
	bool correctInSqr(int startRow, int StartCol);

	void initCells();
	void fillSimpleSudoku(std::string &input);
	void fillSudoku(std::string &input);
	void fillHexadoku(std::string &input);
	void fillAlphadoku(std::string &input);
	std::string simpleSudokuToString();
	std::string sudokuToString();
	std::string hexadokuToString();
	std::string otherToString();
	void rtrim(std::string &s, char c);
};

#endif /* SRC_SUDOKU_HPP_ */
