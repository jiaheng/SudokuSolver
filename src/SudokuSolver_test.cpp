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
	Sudoku solution = solver.getSolution();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float) end - start) / CLOCKS_PER_SEC << "seconds."
			<< std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void solverTest() {
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

void performanceTest() {
	Sudoku sudoku = sampleSudoku();
	SudokuSolver solver(sudoku);
	int start = clock();
	Sudoku solution = solver.getSolution();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float) end - start) / CLOCKS_PER_SEC << "seconds."
			<< std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void solverTest2() {
	Sudoku sudoku = sampleSudoku2();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	Sudoku solution = solver.getSolution();
	std::cout << "\nAfter:\n";
	std::cout << solution.toString();
	ASSERT_EQUAL(true, solution.isCorrect());
}

void performanceTest2() {
	Sudoku sudoku = sampleSudoku2();
	SudokuSolver solver(sudoku);
	int start = clock();
	Sudoku solution = solver.getSolution();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float) end - start) / CLOCKS_PER_SEC << "seconds."
			<< std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void hexadokuSolverTest() {
	Sudoku sudoku = sampleHexadoku();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	Sudoku solution = solver.getSolution();
	std::cout << "\nAfter:\n";
	std::cout << solution.toString();
	ASSERT_EQUAL(true, solution.isCorrect());
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
	for (auto &hexadoku : puzzles) {
		std::cout << "Solving 9x9 puzzle #" << index << "..." << std::endl;
		SudokuSolver solver(hexadoku);
		clock_t start = clock();
		Sudoku solution = solver.getSolution();
		clock_t end = clock();
		time += static_cast<unsigned int>(end - start);
		std::string msg { "Solution for puzzle #" };
		msg += index;
		msg += " is not correct.";
		ASSERT_EQUALM(msg, true, solution.isCorrect());
		index++;
	}
	std::cout << "it took " << time << "ticks, or "
			<< ((float) time) / CLOCKS_PER_SEC
			<< "seconds to solve all 1465 9x9 sudoku." << std::endl;
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
		Sudoku solution = solver.getSolution();
		clock_t end = clock();
		time += static_cast<unsigned int>(end - start);
		std::string msg { "Solution for puzzle #" };
		msg += index;
		msg += " is not correct.";
		ASSERT_EQUALM(msg, true, solution.isCorrect());
		index++;
	}
	std::cout << "it took " << time << "ticks, or "
			<< ((float) time) / CLOCKS_PER_SEC
			<< "seconds to solve all 44 16x16 sudoku." << std::endl;
}

Sudoku simpleSudoku() {
	int **inputs = new int*[4] { };
	inputs[0] = new int[4]{0, 2, 4, 0};
	inputs[1] = new int[4]{0, 0, 0, 2};
	inputs[2] = new int[4]{3, 0, 0, 0};
	inputs[3] = new int[4]{0, 1, 3, 0};

	Sudoku sudoku(inputs, 4);
	for (int i = 0; i < 4; ++i)
		delete[] inputs[i];
	delete[] inputs;
	return sudoku;
}

void dlxTest() {
	Sudoku sudoku = simpleSudoku();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver solver(sudoku);
	Sudoku solution = solver.dlxGetSolution();
	std::cout << "\nAfter:\n";
	std::cout << solution.toString() << std::endl;
	std::cout << "Original:\n" << sudoku.toString() << std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

cute::suite make_suite_SudokuSolver_test() {
	cute::suite s;
	s.push_back(CUTE(hexadokuPerformanceTest));
	s.push_back(CUTE(solverTest));
	s.push_back(CUTE(performanceTest));
	s.push_back(CUTE(solverTest2));
	s.push_back(CUTE(performanceTest2));
	s.push_back(CUTE(hexadokuSolverTest));
	s.push_back(CUTE(dlxTest));
	return s;
}

