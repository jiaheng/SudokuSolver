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

#include "SudokuSolver.hpp"

namespace {
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

	Sudoku sampleSudoku2() {
		int **inputs = new int*[9] { };
		inputs[0] = new int[9] { 9, 0, 0, 0, 4, 0, 0, 0, 0 };
		inputs[1] = new int[9] { 7, 0, 0, 2, 0, 0, 0, 9, 0 };
		inputs[2] = new int[9] { 0, 0, 0, 0, 1, 0, 4, 3, 0 };
		inputs[3] = new int[9] { 0, 6, 0, 0, 0, 3, 0, 2, 0 };
		inputs[4] = new int[9] { 4, 0, 0, 0, 5, 0, 0, 0, 7 };
		inputs[5] = new int[9] { 0, 9, 0, 4, 0, 0, 0, 8, 0 };
		inputs[6] = new int[9] { 0, 8, 4, 0, 6, 0, 0, 0, 0 };
		inputs[7] = new int[9] { 0, 7, 0, 0, 0, 5, 0, 0, 1 };
		inputs[8] = new int[9] { 0, 0, 0, 0, 2, 0, 0, 0, 6 };

		Sudoku sudoku(inputs, 9);
		for (int i = 0; i < 9; ++i)
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

	void verifyResult(Sudoku problem, Sudoku result) {
		EXPECT_TRUE(result.isCorrect()) << "Puzzle is not solved";
		EXPECT_EQ(problem.getSize(), result.getSize()) << "Size of the puzzle not equal!";
		for (int i = 0; i < problem.getSize(); ++i) {
			for (int j = 0; j < problem.getSize(); ++j) {
				if (problem.getCell(i, j) != 0) {
					EXPECT_EQ(problem.getCell(i, j), result.getCell(i, j)) <<
						"the number are not the same at (" + std::to_string(i) + ", " + std::to_string(j) + ").";
				}
			}
		}
	}

	TEST(SudokuSolverTest, SolverTest) {
		Sudoku sudoku = sampleSudoku();
		SudokuSolver solver(sudoku);
		auto result = solver.search();
		EXPECT_GT(result.number_of_solution,  0);
		for (auto solution : result.solutions) {
			EXPECT_TRUE(solution.isCorrect());
		}
	}

	TEST(SudokuSolverTest, SolverTest2) {
		Sudoku sudoku = sampleSudoku2();
		SudokuSolver solver(sudoku);
		auto result = solver.search();
		EXPECT_GT(result.number_of_solution,  0);
		for (auto solution : result.solutions) {
			EXPECT_TRUE(solution.isCorrect());
		}
	}

	TEST(SudokuSolverTest, HexadokuSolverTest) {
		Sudoku sudoku = sampleHexadoku();
		SudokuSolver solver(sudoku);
		auto result = solver.search();
		EXPECT_GT(result.number_of_solution,  0);
		for (auto solution : result.solutions) {
			EXPECT_TRUE(solution.isCorrect());
		}
	}

	TEST(SudokuSolverTest, sudokuBatchSolveTest) {
		std::ifstream infile;
		infile.open("sample/puzzle9_small", std::ifstream::in);
		EXPECT_TRUE(infile.good()) << "FILE NOT EXIST";
		std::string line { };
		std::vector<Sudoku> puzzles { };
		while (std::getline(infile, line)) {
			// read file line by line
			std::istringstream iss(line);
			puzzles.push_back(Sudoku(line));
		}
		infile.close();
		int index { 1 };
		unsigned int time { 0 };
		for (auto &sudoku : puzzles) {
			SudokuSolver solver(sudoku);
			auto result= solver.search();
			std::string msg { "Solution for puzzle #" };
			msg += std::to_string(index);
			msg += " is not correct.";
			EXPECT_GT(result.number_of_solution, 0);
			for (auto solution : result.solutions) {
				EXPECT_TRUE(solution.isCorrect()) << msg;
				verifyResult(sudoku, solution);
			}
			index++;
		}
	}

	TEST(SudokuSolverTest, HexadokuBatchSolveTest) {
		std::ifstream infile;
		infile.open("sample/puzzle16_small", std::ifstream::in);
		EXPECT_TRUE(infile.good()) << "FILE NOT EXIST";
		std::string line { };
		std::vector<Sudoku> puzzles { };
		while (std::getline(infile, line)) {
			// read file line by line
			std::istringstream iss(line);
			puzzles.push_back(Sudoku(line));
		}
		infile.close();
		int index { 1 };
		unsigned int time { 0 };
		for (auto &hexadoku : puzzles) {
			SudokuSolver solver(hexadoku);
			auto result = solver.search();
			std::string msg { "Solution for puzzle #" };
			msg += std::to_string(index);
			msg += " is not correct.";
			EXPECT_GT(result.number_of_solution, 0);
			for (auto solution : result.solutions) {
				EXPECT_TRUE(solution.isCorrect()) << msg;
				verifyResult(hexadoku, solution);
			}
			index++;
		}
	}

	TEST(SudokuSolverTest, SimpleSudokuSolverTest) {
		Sudoku sudoku = simpleSudoku();
		SudokuSolver solver(sudoku);
		auto result = solver.search();
		EXPECT_GT(result.number_of_solution, 0);
		for (auto solution : result.solutions) {
			EXPECT_TRUE(solution.isCorrect());
			verifyResult(sudoku, solution);
		}
	}

	TEST(SudokuSolverTest, SinglePuzzleTest) {
		// for some puzzle that gives error
		std::string input { ".8..1......5....3.......4.....6.5.7.89....2.....3.....2.....1.9..67........4....." };
		Sudoku sudoku {input};
		SudokuSolver solver(sudoku);
		auto result = solver.search();
		EXPECT_GT(result.number_of_solution, 0);
		for (auto solution : result.solutions) {
			EXPECT_TRUE(solution.isCorrect());
			verifyResult(sudoku, solution);
		}
	}
}
