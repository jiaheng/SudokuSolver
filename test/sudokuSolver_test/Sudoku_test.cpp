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

#include "gtest/gtest.h"
#include <iostream>
#include <fstream>

#include "Sudoku.hpp"

namespace {
	Sudoku sampleSudoku() {
		int **inputs = new int*[9] { };
		inputs[0] = new int[9] { 3, 0, 6, 5, 0, 8, 4, 0, 0 };
		inputs[1] = new int[9] { 5, 2, 0, 0, 0, 0, 0, 0, 0 };
		inputs[2] = new int[9] { 0, 8, 7, 0, 0, 0, 0, 3, 1 };
		inputs[3] = new int[9] { 0, 0, 3, 0, 1, 0, 0, 8, 0 };
		inputs[4] = new int[9] { 9, 0, 0, 8, 6, 3, 0, 0, 5 };
		inputs[5] = new int[9] { 0, 5, 0, 0, 9, 0, 6, 0, 0 };
		inputs[6] = new int[9] { 1, 3, 0, 0, 0, 0, 2, 5, 0 };
		inputs[7] = new int[9] { 0, 0, 0, 0, 0, 0, 0, 7, 4 };
		inputs[8] = new int[9] { 0, 0, 5, 2, 0, 6, 3, 0, 0 };
		Sudoku sudoku(inputs, 9);
		for (int i = 0; i < 9; ++i)
			delete[] inputs[i];
		delete[] inputs;
		return sudoku;
	}

	Sudoku completeSudoku() {
		int **inputs = new int*[9] { };
		inputs[0] = new int[9] { 3, 1, 6, 5, 7, 8, 4, 9, 2 };
		inputs[1] = new int[9] { 5, 2, 9, 1, 3, 4, 7, 6, 8 };
		inputs[2] = new int[9] { 4, 8, 7, 6, 2, 9, 5, 3, 1 };
		inputs[3] = new int[9] { 2, 6, 3, 4, 1, 5, 9, 8, 7 };
		inputs[4] = new int[9] { 9, 7, 4, 8, 6, 3, 1, 2, 5 };
		inputs[5] = new int[9] { 8, 5, 1, 7, 9, 2, 6, 4, 3 };
		inputs[6] = new int[9] { 1, 3, 8, 9, 4, 7, 2, 5, 6 };
		inputs[7] = new int[9] { 6, 9, 2, 3, 5, 1, 8, 7, 4 };
		inputs[8] = new int[9] { 7, 4, 5, 2, 8, 6, 3, 1, 9 };

		Sudoku sudoku(inputs, 9);
		for (int i = 0; i < 9; ++i)
			delete[] inputs[i];
		delete[] inputs;
		return sudoku;
	}

	Sudoku simpleSudoku() {
		int **inputs = new int*[4] { };
		inputs[0] = new int[4] { 0, 2, 4, 0 };
		inputs[1] = new int[4] { 0, 0, 0, 2 };
		inputs[2] = new int[4] { 3, 0, 0, 0 };
		inputs[3] = new int[4] { 0, 1, 3, 0 };

		Sudoku sudoku(inputs, 4);
		for (int i = 0; i < 4; ++i)
			delete[] inputs[i];
		delete[] inputs;
		return sudoku;
	}

	Sudoku simpleCompleteSudoku() {
		int **inputs = new int*[4] { };
		inputs[0] = new int[4] { 1, 2, 4, 3 };
		inputs[1] = new int[4] { 4, 3, 1, 2 };
		inputs[2] = new int[4] { 3, 4, 2, 1 };
		inputs[3] = new int[4] { 2, 1, 3, 4 };

		Sudoku sudoku(inputs, 4);
		for (int i = 0; i < 4; ++i)
			delete[] inputs[i];
		delete[] inputs;
		return sudoku;
	}

	Sudoku sampleHexadoku() {
		int **inputs = new int*[16] { };
		inputs[0] = new int[16] { 4, 3, 7, 11, 14, 0, 13, 2, 16, 10, 0, 8, 0, 9, 0,
				15 };
		inputs[1] =
				new int[16] { 6, 0, 0, 1, 5, 8, 9, 0, 13, 0, 2, 0, 10, 0, 4, 0 };
		inputs[2] = new int[16] { 2, 0, 9, 10, 0, 6, 0, 0, 0, 5, 3, 0, 0, 0, 0, 0 };
		inputs[3] =
				new int[16] { 14, 13, 0, 5, 0, 0, 10, 4, 7, 1, 9, 0, 0, 0, 8, 12 };
		inputs[4] = new int[16] { 9, 0, 10, 4, 1, 11, 3, 5, 8, 2, 12, 6, 13, 15, 0,
				0 };
		inputs[5] = new int[16] { 0, 11, 2, 12, 0, 9, 16, 0, 10, 0, 14, 0, 0, 0, 0,
				0 };
		inputs[6] =
				new int[16] { 1, 5, 0, 0, 10, 2, 0, 8, 0, 11, 4, 13, 9, 0, 0, 0 };
		inputs[7] =
				new int[16] { 0, 6, 8, 0, 13, 0, 0, 12, 0, 9, 0, 16, 11, 0, 0, 0 };
		inputs[8] =
				new int[16] { 0, 0, 0, 6, 3, 0, 2, 0, 1, 0, 0, 12, 0, 14, 15, 0 };
		inputs[9] = new int[16] { 0, 0, 0, 2, 8, 14, 12, 0, 11, 0, 15, 3, 0, 0, 10,
				9 };
		inputs[10] =
				new int[16] { 0, 0, 0, 0, 0, 13, 0, 7, 0, 6, 8, 0, 3, 12, 1, 0 };
		inputs[11] = new int[16] { 0, 0, 13, 14, 11, 15, 1, 6, 9, 7, 5, 10, 4, 8, 0,
				2 };
		inputs[12] = new int[16] { 7, 1, 0, 0, 0, 10, 8, 13, 4, 12, 0, 0, 15, 0, 3,
				6 };
		inputs[13] =
				new int[16] { 0, 0, 0, 0, 0, 16, 5, 0, 0, 0, 10, 0, 8, 1, 0, 4 };
		inputs[14] =
				new int[16] { 0, 4, 0, 15, 0, 7, 0, 3, 0, 8, 1, 9, 14, 0, 0, 10 };
		inputs[15] = new int[16] { 11, 0, 3, 0, 4, 0, 15, 14, 6, 16, 0, 5, 12, 2, 9,
				7 };

		Sudoku sudoku(inputs, 16);
		for (int i = 0; i < 16; ++i)
			delete[] inputs[i];
		delete[] inputs;
		return sudoku;
	}

	TEST(SudokuTest, ConstructorTest) {
		int **inputs = new int*[9] { };
		for (int i = 0; i < 9; ++i)
			inputs[i] = new int[9] { };
		Sudoku sudoku(inputs, 9);
		for (int i = 0; i < 9; ++i)
			delete[] inputs[i];
		delete[] inputs;
	}

	TEST(SudokuTest, SetterTest) {
		int size { 9 };
		int **inputs = new int*[size] { };
		for (int i = 0; i < size; ++i)
			inputs[i] = new int[size] { };
		Sudoku sudoku(inputs, size);
		for (int i = 0; i < size; ++i)
			delete[] inputs[i];
		delete[] inputs;
		sudoku.setCell(0, 0, 1);
		int cond = sudoku.getCell(0, 0);
		EXPECT_EQ(1, cond);
		for (int j = 1; j < size; j++) {
			int cond = sudoku.getCell(0, j);
			EXPECT_EQ(0, cond);
		}
		for (int i = 1; i < size; i++)
			for (int j = 0; j < size; j++) {
				int cond = sudoku.getCell(i, j);
				EXPECT_EQ(0, cond);
			}
	}

	TEST(SudokuTest, SetterTest2) {
		int size { 16 };
		int **inputs = new int*[size] { };
		for (int i = 0; i < size; ++i)
			inputs[i] = new int[size] { };
		Sudoku sudoku(inputs, size);
		for (int i = 0; i < size; ++i)
			delete[] inputs[i];
		delete[] inputs;
		sudoku.setCell(0, 0, 1);
		int cond = sudoku.getCell(0, 0);
		EXPECT_EQ(1, cond);
		for (int j = 1; j < size; j++) {
			int cond = sudoku.getCell(0, j);
			EXPECT_EQ(0, cond);
		}
		for (int i = 1; i < size; i++)
			for (int j = 0; j < size; j++) {
				int cond = sudoku.getCell(i, j);
				EXPECT_EQ(0, cond);
			}
	}

	TEST(SudokuTest, GetterTest) {
		int size { 9 };
		int **inputs = new int*[size] { };
		for (int i = 0; i < size; ++i)
			inputs[i] = new int[size] { };
		Sudoku sudoku(inputs, size);
		for (int i = 0; i < size; ++i)
			delete[] inputs[i];
		delete[] inputs;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				int cond = sudoku.getCell(i, j);
				EXPECT_EQ(0, cond);
			}
	}

	TEST(SudokuTest, GetterTest2) {
		int size { 16 };
		int **inputs = new int*[size] { };
		for (int i = 0; i < size; ++i)
			inputs[i] = new int[size] { };
		Sudoku sudoku(inputs, size);
		for (int i = 0; i < size; ++i)
			delete[] inputs[i];
		delete[] inputs;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				int cond = sudoku.getCell(i, j);
				EXPECT_EQ(0, cond);
			}
	}

	TEST(SudokuTest, GetterTest3) {
		Sudoku sudoku = sampleSudoku();
		EXPECT_EQ(3, sudoku.getCell(0, 0));
	}

	TEST(SudokuTest, IsIncompleteTest) {
		int size { 9 };
		int **inputs = new int*[size] { };
		for (int i = 0; i < size; ++i)
			inputs[i] = new int[size] { };
		Sudoku sudoku(inputs, size);
		for (int i = 0; i < size; ++i)
			delete[] inputs[i];
		delete[] inputs;
		EXPECT_TRUE(sudoku.isIncomplete());
	}

	TEST(SudokuTest, IsIncompleteTest2) {
		Sudoku sudoku = sampleSudoku();
		EXPECT_TRUE(sudoku.isIncomplete());
	}

	TEST(SudokuTest, IsIncompleteTest3) {
		Sudoku sudoku = completeSudoku();
		EXPECT_FALSE(sudoku.isIncomplete());
	}

	TEST(SudokuTest, IsCompleteTest) {
		int size { 9 };
		int **inputs = new int*[size] { };
		for (int i = 0; i < size; ++i)
			inputs[i] = new int[size] { };
		Sudoku sudoku(inputs, size);
		for (int i = 0; i < size; ++i)
			delete[] inputs[i];
		delete[] inputs;
		EXPECT_FALSE(sudoku.isComplete());
	}

	TEST(SudokuTest, IsCompleteTest2) {
		Sudoku sudoku = sampleSudoku();
		EXPECT_FALSE(sudoku.isComplete());
	}

	TEST(SudokuTest, IsCompleteTest3) {
		Sudoku sudoku = completeSudoku();
		EXPECT_TRUE(sudoku.isComplete());
	}

	TEST(SudokuTest, IsCorrectTest) {
		int size { 9 };
		int **inputs = new int*[size] { };
		for (int i = 0; i < size; ++i)
			inputs[i] = new int[size] { };
		Sudoku sudoku(inputs, size);
		for (int i = 0; i < size; ++i)
			delete[] inputs[i];
		delete[] inputs;
		EXPECT_FALSE(sudoku.isCorrect());
	}

	TEST(SudokuTest, IsCorrectTest2) {
		Sudoku sudoku = sampleSudoku();
		EXPECT_FALSE(sudoku.isCorrect());
	}

	TEST(SudokuTest, IsCorrectTest3) {
		Sudoku sudoku = completeSudoku();
		EXPECT_TRUE(sudoku.isCorrect());
	}

	TEST(SudokuTest, CopyConstructorTest) {
		int size { 9 };
		int **inputs = new int*[size] { };
		for (int i = 0; i < size; ++i)
			inputs[i] = new int[size] { };
		Sudoku sudoku(inputs, size);
		for (int i = 0; i < size; ++i)
			delete[] inputs[i];
		delete[] inputs;
		Sudoku copy(sudoku);
		copy.setCell(0, 0, 1);
		EXPECT_EQ(0, sudoku.getCell(0, 0));
		EXPECT_EQ(1, copy.getCell(0, 0));
		EXPECT_EQ(sudoku.getCell(0, 1), copy.getCell(0, 1)) << "copied sudoku should have same value in [0,1]";
		std::string msg { "method error in copied object" };
		EXPECT_FALSE(copy.cellIsEmpty(0, 0)) << msg;
		EXPECT_TRUE(copy.cellIsEmpty(0, 1)) << msg;
		EXPECT_FALSE(copy.isComplete()) << msg;
	}

	TEST(SudokuTest, HexadokuTest) {
		Sudoku hexadoku = sampleHexadoku();
		EXPECT_TRUE(hexadoku.isIncomplete());
		EXPECT_FALSE(hexadoku.isComplete());
		EXPECT_FALSE(hexadoku.isCorrect());
	}

	TEST(SudokuTest, HexadokuFromStringTest) {
		std::string input {
				".63B.EC..A..8....847..A6..B....9.....81.D.G...7E.......7..98...CF.D.....AC..2.......D.....E1..5.CE......6...GF.31A.9...B8G7.4..D2.E...45....69.F.7......E..A...5..94..6......D.....63..F79.5...A....E6.D.1...2.8...3G.FA56.......D.C...9...B1.6..2..B.5C9.....34" };
		Sudoku hexadoku(input);
		EXPECT_TRUE(hexadoku.isIncomplete());
		EXPECT_FALSE(hexadoku.isComplete());
		EXPECT_FALSE(hexadoku.isCorrect());
		EXPECT_EQ(0, hexadoku.getCell(0, 0));
		EXPECT_EQ(6, hexadoku.getCell(0, 1));
		EXPECT_EQ(11, hexadoku.getCell(0, 3));
		EXPECT_EQ(4, hexadoku.getCell(15, 15));
	}

	TEST(SudokuTest, IsEmptyTest) {
		Sudoku sudoku = sampleSudoku();
		EXPECT_FALSE(sudoku.cellIsEmpty(0, 0));
		EXPECT_TRUE(sudoku.cellIsEmpty(0, 1));
	}

	TEST(SudokuTest, IsSafeTest) {
		Sudoku sudoku = sampleSudoku();
		// acceptable number 1, 9 at cell (0,1)
		EXPECT_TRUE(sudoku.isSafe(0, 1, 1));
		EXPECT_TRUE(sudoku.isSafe(0, 1, 9));
	}

	TEST(SudokuTest, IsSafeTest2) {
		Sudoku sudoku = sampleSudoku();
		// unacceptable number 2, 3, 4, 5, 6, 7, 8 at cell (0,1)
		EXPECT_FALSE(sudoku.isSafe(0, 1, 2));
		EXPECT_FALSE(sudoku.isSafe(0, 1, 3));
		EXPECT_FALSE(sudoku.isSafe(0, 1, 4));
		EXPECT_FALSE(sudoku.isSafe(0, 1, 5));
		EXPECT_FALSE(sudoku.isSafe(0, 1, 6));
		EXPECT_FALSE(sudoku.isSafe(0, 1, 7));
		EXPECT_FALSE(sudoku.isSafe(0, 1, 8));
		// unacceptable number all at cell (0,0)
		EXPECT_FALSE(sudoku.isSafe(0, 0, 1));
		EXPECT_FALSE(sudoku.isSafe(0, 0, 2));
		EXPECT_FALSE(sudoku.isSafe(0, 0, 3));
		EXPECT_FALSE(sudoku.isSafe(0, 0, 4));
		EXPECT_FALSE(sudoku.isSafe(0, 0, 5));
		EXPECT_FALSE(sudoku.isSafe(0, 0, 6));
		EXPECT_FALSE(sudoku.isSafe(0, 0, 7));
		EXPECT_FALSE(sudoku.isSafe(0, 0, 8));
		EXPECT_FALSE(sudoku.isSafe(0, 0, 9));
	}

	TEST(SudokuTest, SimpleSudokuTest) {
		Sudoku sudoku = simpleSudoku();
		sudoku.toString();
		EXPECT_EQ(2, sudoku.getCell(0, 1));
		EXPECT_FALSE(sudoku.isComplete()) << "Sudoku is expected to be incomplete";
		EXPECT_FALSE(sudoku.isCorrect()) << "Sudoku is expected to be incorrect";
		EXPECT_TRUE(sudoku.isSafe(0, 0, 1)) << "expect isSafe(0, 0, 1) return true";
		EXPECT_FALSE(sudoku.isSafe(0, 0, 2)) << "expect isSafe(0, 0, 2) return false";
		EXPECT_FALSE(sudoku.isSafe(0, 0, 3)) << "expect isSafe(0, 0, 3) return false";
		EXPECT_FALSE(sudoku.isSafe(0, 0, 4)) << "expect isSafe(0, 0, 4) return false";
		EXPECT_TRUE(sudoku.isSafe(0, 3, 3)) << "expect isSafe(0, 3, 3) return true";
		EXPECT_FALSE(sudoku.isSafe(3, 3, 1)) << "expect isSafe(3, 3, 1) return false";
		EXPECT_FALSE(sudoku.isSafe(3, 3, 2)) << "expect isSafe(3, 3, 2) return false";
		EXPECT_FALSE(sudoku.isSafe(3, 3, 3)) << "expect isSafe(3, 3, 3) return false";
		EXPECT_TRUE(sudoku.isSafe(3, 3, 4)) << "expect isSafe(3, 3, 4) return true";
		EXPECT_FALSE(sudoku.isSafe(3, 0, 1)) << "expect isSafe(3, 0, 1) return false";
		EXPECT_TRUE(sudoku.isSafe(3, 0, 2)) << "expect isSafe(3, 0, 2) return true";
		EXPECT_FALSE(sudoku.isSafe(3, 0, 1)) << "expect isSafe(3, 0, 3) return false";
		EXPECT_TRUE(sudoku.isSafe(3, 0, 4)) << "expect isSafe(3, 0, 4) return true";
	}

	TEST(SudokuTest, SimpleSudokuTest2) {
		Sudoku sudoku = simpleCompleteSudoku();
		EXPECT_TRUE(sudoku.isComplete());
		EXPECT_TRUE(sudoku.isCorrect());
	}

	TEST(SudokuTest, ToSimpleStringTest) {
		std::ifstream infile;
		infile.open("sample/puzzle9", std::ifstream::in);
		EXPECT_TRUE(infile.good()) << "FILE NOT EXIST";
		std::string line { };
		int index { 1 };
		while (std::getline(infile, line)) {
			// read file line by line
			std::istringstream iss(line);
			Sudoku sudoku {line};
			std::string result = sudoku.toSimpleString();
			std::string msg = "9x9 puzzle " + std::to_string(index) + " not equal!!!     ";
			msg += "expected:    " + line + "    ";
			msg += "result:      " + result;
			EXPECT_EQ(0, line.compare(result)) << msg;
			++index;
		}
		infile.close();
		infile.open("sample/puzzle16", std::ifstream::in);;
		EXPECT_TRUE(infile.good()) << "FILE NOT EXIST";
		line = "";
		index = 1;
		while (std::getline(infile, line)) {
			// read file line by line
			std::istringstream iss(line);
			Sudoku sudoku {line};
			std::string result = sudoku.toSimpleString();
			std::string msg = "16x16 puzzle " + std::to_string(index) + " not equal!!!     ";
			msg += "expected:    " + line + "    ";
			msg += "result:      " + result;
			EXPECT_EQ(0, line.compare(result)) << msg;
			++index;
		}
		infile.close();
	}
}
