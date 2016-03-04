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

#include <iostream>
#include <fstream>

#include "cute.h"
#include "SudokuSolver_test.h"
#include "Sudoku_test.h"
#include "SudokuSolver.hpp"

void hexadokuPerformanceTest() {
	Sudoku sudoku = sampleHexadoku();
	SudokuSolver solver(sudoku);
	int start = clock();
	auto result = solver.search();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float) end - start) / CLOCKS_PER_SEC << "seconds."
			<< std::endl;
	ASSERT(result.number_of_solution > 0);
	for (auto solution : result.solutions) {
		ASSERT(solution.isCorrect());
	}
}

void solverTest() {
	Sudoku sudoku = sampleSudoku();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	auto result = solver.search();
	std::cout << "\nAfter:\n";
	ASSERT(result.number_of_solution > 0);
	for (auto solution : result.solutions) {
		ASSERT(solution.isCorrect());
		std::cout << solution.toString() << std::endl;
	}
}

void performanceTest() {
	Sudoku sudoku = sampleSudoku();
	SudokuSolver solver(sudoku);
	int start = clock();
	auto result = solver.search();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float) end - start) / CLOCKS_PER_SEC << "seconds."
			<< std::endl;
	ASSERT(result.number_of_solution > 0);
	for (auto solution : result.solutions) {
		ASSERT(solution.isCorrect());
	}
}

void solverTest2() {
	Sudoku sudoku = sampleSudoku2();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	auto result = solver.search();
	std::cout << "\nAfter:\n";
	ASSERT(result.number_of_solution > 0);
	for (auto solution : result.solutions) {
		ASSERT(solution.isCorrect());
		std::cout << solution.toString() << std::endl;
	}
}

void performanceTest2() {
	Sudoku sudoku = sampleSudoku2();
	SudokuSolver solver(sudoku);
	int start = clock();
	auto result = solver.search();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float) end - start) / CLOCKS_PER_SEC << "seconds."
			<< std::endl;
	ASSERT(result.number_of_solution > 0);
	for (auto solution : result.solutions) {
		ASSERT(solution.isCorrect());
	}
}

void hexadokuSolverTest() {
	Sudoku sudoku = sampleHexadoku();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	auto result = solver.search();
	std::cout << "\nAfter:\n";
	ASSERT(result.number_of_solution > 0);
	for (auto solution : result.solutions) {
		ASSERT(solution.isCorrect());
		std::cout << solution.toString() << std::endl;
	}
}

void sudokuBatchSolveTest() {
	std::ifstream infile("puzzle9");
	ASSERT_EQUALM("FILE NOT EXIST", true, infile.good());
	std::string line { };
	std::vector<Sudoku> puzzles { };
	while (std::getline(infile, line)) {
		// read file line by line
		std::istringstream iss(line);
		puzzles.push_back(Sudoku(line));
	}
	int index { 1 };
	unsigned int time { 0 };
	for (auto &sudoku : puzzles) {
		std::cout << "Solving 9x9 puzzle #" << index << "..." << std::endl;
		SudokuSolver solver(sudoku);
		clock_t start = clock();
		auto result= solver.search();
		clock_t end = clock();
		time += static_cast<unsigned int>(end - start);
		std::string msg { "Solution for puzzle #" };
		msg += std::to_string(index);
		msg += " is not correct.";
		ASSERT(result.number_of_solution > 0);
		for (auto solution : result.solutions) {
			ASSERTM(msg, solution.isCorrect());
			verifyResult(sudoku, solution);
		}
		index++;
	}
	std::cout << "it took " << time << "ticks, or "
			<< ((float) time) / CLOCKS_PER_SEC
			<< "seconds to solve all 1465 9x9 sudoku." << std::endl;
	ASSERT(true);
}

void hexadokuBatchSolveTest() {
	std::ifstream infile("puzzle16");
	ASSERT_EQUALM("FILE NOT EXIST", true, infile.good());
	std::string line { };
	std::vector<Sudoku> puzzles { };
	while (std::getline(infile, line)) {
		// read file line by line
		std::istringstream iss(line);
		puzzles.push_back(Sudoku(line));
	}
	int index { 1 };
	unsigned int time { 0 };
	for (auto &hexadoku : puzzles) {
		std::cout << "Solving 16x16 puzzle #" << index << "..." << std::endl;
		SudokuSolver solver(hexadoku);
		clock_t start = clock();
		auto result = solver.search();
		clock_t end = clock();
		time += static_cast<unsigned int>(end - start);
		std::string msg { "Solution for puzzle #" };
		msg += std::to_string(index);
		msg += " is not correct.";
		ASSERT(result.number_of_solution > 0);
		for (auto solution : result.solutions) {
			ASSERTM(msg, solution.isCorrect());
			verifyResult(hexadoku, solution);
		}
		index++;
	}
	std::cout << "it took " << time << "ticks, or "
			<< ((float) time) / CLOCKS_PER_SEC
			<< "seconds to solve all 44 16x16 sudoku." << std::endl;
	ASSERT(true);
}

void simpleSudokuSolverTest() {
	Sudoku sudoku = simpleSudoku();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	auto result = solver.search();
	std::cout << "\nAfter:\n";
	ASSERT(result.number_of_solution > 0);
	for (auto solution : result.solutions) {
		ASSERT(solution.isCorrect());
		verifyResult(sudoku, solution);
		std::cout << solution.toString() << std::endl;
	}
}

void singlePuzzleTest() {
	// for some puzzle that gives error
	std::string input { ".8..1......5....3.......4.....6.5.7.89....2.....3.....2.....1.9..67........4....." };
	Sudoku sudoku {input};
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	auto result = solver.search();
	std::cout << "\nAfter:\n";
	ASSERT(result.number_of_solution > 0);
	for (auto solution : result.solutions) {
		ASSERT(solution.isCorrect());
		verifyResult(sudoku, solution);
		std::cout << solution.toString() << std::endl;
	}
}

void verifyResult(Sudoku problem, Sudoku result) {
	ASSERTM("Puzzle is not solved", result.isCorrect());
	ASSERTM("Size of the puzzle not equal!", problem.getSize() == result.getSize());
	for (int i = 0; i < problem.getSize(); ++i) {
		for (int j = 0; j < problem.getSize(); ++j) {
			if (problem.getCell(i, j) != 0) {
				std::string msg = "the number are not the same at (" + std::to_string(i) + ", " + std::to_string(j) + ").";
				ASSERTM(msg, problem.getCell(i, j) == result.getCell(i, j));
			}
		}
	}
}

cute::suite make_suite_SudokuSolver_test() {
	cute::suite s;
	s.push_back(CUTE(hexadokuPerformanceTest));
	s.push_back(CUTE(solverTest));
	s.push_back(CUTE(performanceTest));
	s.push_back(CUTE(solverTest2));
	s.push_back(CUTE(performanceTest2));
	s.push_back(CUTE(hexadokuSolverTest));
	s.push_back(CUTE(simpleSudokuSolverTest));
	s.push_back(CUTE(singlePuzzleTest));
	s.push_back(CUTE(sudokuBatchSolveTest));
	s.push_back(CUTE(hexadokuBatchSolveTest));
	return s;
}

