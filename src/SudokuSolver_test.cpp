/*
 * SudokuSolver_test.cpp
 *
 *  Created on: 12 Feb 2016
 *      Author: jiaheng
 */

#include <iostream>
#include <fstream>

#include "cute.h"
#include "SudokuSolver_test.hpp"
#include "SudokuSolver.hpp"

SudokuSolver_test::SudokuSolver_test() {
	std::cout << "Call from Sudoku Solver test constructor" << std::endl;
}

void SudokuSolver_test::operator ()() {
	std::cout<< "Call from Sudoku Solver test operator" << std::endl;
}

void SudokuSolver_test::hexadokuPerformanceTest() {
	Sudoku sudoku = sampleHexadoku();
	SudokuSolver solver(sudoku);
	int start = clock();
	Sudoku solution = solver.getSolution();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float)end - start)/CLOCKS_PER_SEC
			<< "seconds." << std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void SudokuSolver_test::solverTest() {
	Sudoku sudoku = sampleSudoku();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	Sudoku solution = solver.getSolution();
	std::cout << "\nAfter:\n";
	std::cout << solution.toString() << std::endl;
	std::cout << "Original:\n" << sudoku.toString() << std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void SudokuSolver_test::performanceTest() {
	Sudoku sudoku = sampleSudoku();
	SudokuSolver solver(sudoku);
	int start = clock();
	Sudoku solution = solver.getSolution();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float)end - start)/CLOCKS_PER_SEC
			<< "seconds." << std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void SudokuSolver_test::solverTest2() {
	Sudoku sudoku = sampleSudoku2();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	Sudoku solution = solver.getSolution();
	std::cout << "\nAfter:\n";
	std::cout << solution.toString();
	ASSERT_EQUAL(true, solution.isCorrect());
}

void SudokuSolver_test::performanceTest2() {
	Sudoku sudoku = sampleSudoku2();
	SudokuSolver solver(sudoku);
	int start = clock();
	Sudoku solution = solver.getSolution();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float)end - start)/CLOCKS_PER_SEC
			<< "seconds." << std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void SudokuSolver_test::hexadokuSolverTest() {
	Sudoku sudoku = sampleHexadoku();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	Sudoku solution = solver.getSolution();
	std::cout << "\nAfter:\n";
	std::cout << solution.toString();
	ASSERT_EQUAL(true, solution.isCorrect());
}

void SudokuSolver_test::sudokuBatchSolveTest() {
	std::ifstream infile("puzzle9");
	ASSERT_EQUALM("FILE NOT EXIST", true, infile.good());
	std::string line { };
	std::vector<Sudoku> puzzles { };
	while (std::getline(infile, line)) {
		// read file line by line
	    std::istringstream iss(line);
	    puzzles.push_back(Sudoku(line));
	}
	int index {1};
	unsigned int time {0};
	for (auto &hexadoku: puzzles) {
		std::cout << "Solving 9x9 puzzle #" << index << "..." << std::endl;
		SudokuSolver solver(hexadoku);
		clock_t start = clock();
		Sudoku solution = solver.getSolution();
		clock_t end = clock();
		time += static_cast<unsigned int>(end - start);
		std::string msg {"Solution for puzzle #"};
		msg += index;
		msg += " is not correct.";
		ASSERT_EQUALM(msg, true, solution.isCorrect());
		index++;
	}
	std::cout << "it took " << time << "ticks, or "
				<< ((float)time)/CLOCKS_PER_SEC
				<< "seconds to solve all 1465 9x9 sudoku." << std::endl;
}

void SudokuSolver_test::hexadokuBatchSolveTest() {
	std::ifstream infile("puzzle16");
	ASSERT_EQUALM("FILE NOT EXIST", true, infile.good());
	std::string line { };
	std::vector<Sudoku> puzzles { };
	while (std::getline(infile, line)) {
		// read file line by line
		std::istringstream iss(line);
		puzzles.push_back(Sudoku(line));
	}
	int index {1};
	unsigned int time {0};
	for (auto &hexadoku: puzzles) {
		std::cout << "Solving 16x16 puzzle #" << index << "..." << std::endl;
		SudokuSolver solver(hexadoku);
		clock_t start = clock();
		Sudoku solution = solver.getSolution();
		clock_t end = clock();
		time += static_cast<unsigned int>(end - start);
		std::string msg {"Solution for puzzle #"};
		msg += index;
		msg += " is not correct.";
		ASSERT_EQUALM(msg, true, solution.isCorrect());
		index++;
	}
	std::cout << "it took " << time << "ticks, or "
				<< ((float)time)/CLOCKS_PER_SEC
				<< "seconds to solve all 44 16x16 sudoku." << std::endl;
}

Sudoku SudokuSolver_test::sampleSudoku() {
	int **inputs = new int*[9] { };
	inputs[0] = new int[9]{3, 0, 6, 5, 0, 8, 4, 0, 0};
	inputs[1] = new int[9]{5, 2, 0, 0, 0, 0, 0, 0, 0};
	inputs[2] = new int[9]{0, 8, 7, 0, 0, 0, 0, 3, 1};
	inputs[3] = new int[9]{0, 0, 3, 0, 1, 0, 0, 8, 0};
	inputs[4] = new int[9]{9, 0, 0, 8, 6, 3, 0, 0, 5};
	inputs[5] = new int[9]{0, 5, 0, 0, 9, 0, 6, 0, 0};
	inputs[6] = new int[9]{1, 3, 0, 0, 0, 0, 2, 5, 0};
	inputs[7] = new int[9]{0, 0, 0, 0, 0, 0, 0, 7, 4};
	inputs[8] = new int[9]{0, 0, 5, 2, 0, 6, 3, 0, 0};
	Sudoku sudoku(inputs, 9);
	for (int i = 0; i < 9; ++i)
		delete[] inputs[i];
	delete[] inputs;
	return sudoku;
}

Sudoku SudokuSolver_test::sampleSudoku2() {
	int **inputs = new int*[9] { };
	inputs[0] = new int[9]{9, 0, 0, 0, 4, 0, 0, 0, 0};
	inputs[1] = new int[9]{7, 0, 0, 2, 0, 0, 0, 9, 0};
	inputs[2] = new int[9]{0, 0, 0, 0, 1, 0, 4, 3, 0};
	inputs[3] = new int[9]{0, 6, 0, 0, 0, 3, 0, 2, 0};
	inputs[4] = new int[9]{4, 0, 0, 0, 5, 0, 0, 0, 7};
	inputs[5] = new int[9]{0, 9, 0, 4, 0, 0, 0, 8, 0};
	inputs[6] = new int[9]{0, 8, 4, 0, 6, 0, 0, 0, 0};
	inputs[7] = new int[9]{0, 7, 0, 0, 0, 5, 0, 0, 1};
	inputs[8] = new int[9]{0, 0, 0, 0, 2, 0, 0, 0, 6};

	Sudoku sudoku(inputs, 9);
	for (int i = 0; i < 9; ++i)
		delete[] inputs[i];
	delete[] inputs;
	return sudoku;
}

Sudoku SudokuSolver_test::completeSudoku() {
	int **inputs = new int*[9] { };
	inputs[0] = new int[9]{3, 1, 6, 5, 7, 8, 4, 9, 2};
	inputs[1] = new int[9]{5, 2, 9, 1, 3, 4, 7, 6, 8};
	inputs[2] = new int[9]{4, 8, 7, 6, 2, 9, 5, 3, 1};
	inputs[3] = new int[9]{2, 6, 3, 4, 1, 5, 9, 8, 7};
	inputs[4] = new int[9]{9, 7, 4, 8, 6, 3, 1, 2, 5};
	inputs[5] = new int[9]{8, 5, 1, 7, 9, 2, 6, 4, 3};
	inputs[6] = new int[9]{1, 3, 8, 9, 4, 7, 2, 5, 6};
	inputs[7] = new int[9]{6, 9, 2, 3, 5, 1, 8, 7, 4};
	inputs[8] = new int[9]{7, 4, 5, 2, 8, 6, 3, 1, 9};

	Sudoku sudoku(inputs, 9);
	for (int i = 0; i < 9; ++i)
		delete[] inputs[i];
	delete[] inputs;
	return sudoku;
}

Sudoku SudokuSolver_test::sampleHexadoku() {
	int **inputs = new int*[16] { };
	inputs[0] = new int[16]{4, 3, 7, 11, 14, 0, 13, 2, 16, 10, 0, 8, 0, 9, 0, 15};
	inputs[1] = new int[16]{6, 0, 0, 1, 5, 8, 9, 0, 13, 0, 2, 0, 10, 0, 4, 0};
	inputs[2] = new int[16]{2, 0, 9, 10, 0, 6, 0, 0, 0, 5, 3, 0, 0, 0, 0, 0};
	inputs[3] = new int[16]{14, 13, 0, 5, 0, 0, 10, 4, 7, 1, 9, 0, 0, 0, 8, 12};
	inputs[4] = new int[16]{9, 0, 10, 4, 1, 11, 3, 5, 8, 2, 12, 6, 13, 15, 0, 0};
	inputs[5] = new int[16]{0, 11, 2, 12, 0, 9, 16, 0, 10, 0, 14, 0, 0, 0, 0, 0};
	inputs[6] = new int[16]{1, 5, 0, 0, 10, 2, 0, 8, 0, 11, 4, 13, 9, 0, 0, 0};
	inputs[7] = new int[16]{0, 6, 8, 0, 13, 0, 0, 12, 0, 9, 0, 16, 11, 0, 0, 0};
	inputs[8] = new int[16]{0, 0, 0, 6, 3, 0, 2, 0, 1, 0, 0, 12, 0, 14, 15, 0};
	inputs[9] = new int[16]{0, 0, 0, 2, 8, 14, 12, 0, 11, 0, 15, 3, 0, 0, 10, 9};
	inputs[10] = new int[16]{0, 0, 0, 0, 0, 13, 0, 7, 0, 6, 8, 0, 3, 12, 1, 0};
	inputs[11] = new int[16]{0, 0, 13, 14, 11, 15, 1, 6, 9, 7, 5, 10, 4, 8, 0, 2};
	inputs[12] = new int[16]{7, 1, 0, 0, 0, 10, 8, 13, 4, 12, 0, 0, 15, 0, 3, 6};
	inputs[13] = new int[16]{0, 0, 0, 0, 0, 16, 5, 0, 0, 0, 10, 0, 8, 1, 0, 4};
	inputs[14] = new int[16]{0, 4, 0, 15, 0, 7, 0, 3, 0, 8, 1, 9, 14, 0, 0, 10};
	inputs[15] = new int[16]{11, 0, 3, 0, 4, 0, 15, 14, 6, 16, 0, 5, 12, 2, 9, 7};

	Sudoku sudoku(inputs, 16);
	for (int i = 0; i < 16; ++i)
		delete[] inputs[i];
	delete[] inputs;
	return sudoku;
}

cute::suite SudokuSolver_test::make_suite(){
	cute::suite s;
	s.push_back(CUTE_SMEMFUN(SudokuSolver_test, hexadokuPerformanceTest));
	s.push_back(CUTE_SMEMFUN(SudokuSolver_test, solverTest));
	s.push_back(CUTE_SMEMFUN(SudokuSolver_test, performanceTest));
	s.push_back(CUTE_SMEMFUN(SudokuSolver_test, solverTest2));
	s.push_back(CUTE_SMEMFUN(SudokuSolver_test, performanceTest2));
	s.push_back(CUTE_SMEMFUN(SudokuSolver_test, hexadokuSolverTest));
	return s;
}
