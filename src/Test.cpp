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

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "Sudoku.hpp"
#include "SudokuSolver.hpp"

Sudoku sampleSudoku() {
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

Sudoku sampleSudoku2() {
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

Sudoku completeSudoku() {
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

Sudoku sampleHexadoku() {
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

void constructorTest() {
	int **inputs = new int*[9] { };
	for (int i = 0; i < 9; ++i)
		inputs[i] = new int[9] { };
	Sudoku sudoku(inputs, 9);
	for (int i = 0; i < 9; ++i)
		delete[] inputs[i];
	delete[] inputs;
}

void setterTest() {
	int size { 9 };
	int **inputs = new int*[size] { };
	for (int i = 0; i < size; ++i)
		inputs[i] = new int[size] { };
	Sudoku sudoku(inputs, size);
	for (int i = 0; i < size; ++i)
		delete[] inputs[i];
	delete[] inputs;
	sudoku.setCell(0,0,1);
	int cond = sudoku.getCell(0,0);
	ASSERT_EQUAL(1, cond);
	for (int j = 1; j < size; j++) {
		int cond = sudoku.getCell(0, j);
		ASSERT_EQUAL(0, cond);
	}
	for (int i = 1; i < size; i++)
		for (int j = 0; j < size; j++) {
			int cond = sudoku.getCell(i, j);
			ASSERT_EQUAL(0, cond);
		}
}

void setterTest2() {
	int size { 16 };
	int **inputs = new int*[size] { };
	for (int i = 0; i < size; ++i)
		inputs[i] = new int[size] { };
	Sudoku sudoku(inputs, size);
	for (int i = 0; i < size; ++i)
		delete[] inputs[i];
	delete[] inputs;
	sudoku.setCell(0,0,1);
	int cond = sudoku.getCell(0,0);
	ASSERT_EQUAL(1, cond);
	for (int j = 1; j < size; j++) {
		int cond = sudoku.getCell(0, j);
		ASSERT_EQUAL(0, cond);
	}
	for (int i = 1; i < size; i++)
		for (int j = 0; j < size; j++) {
			int cond = sudoku.getCell(i, j);
			ASSERT_EQUAL(0, cond);
		}
}

void getterTest() {
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
			ASSERT_EQUAL(0, cond);
		}
}

void getterTest2() {
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
			ASSERT_EQUAL(0, cond);
		}
}

void getterTest3() {
	Sudoku sudoku = sampleSudoku();
	ASSERT_EQUAL(3, sudoku.getCell(0,0));
}

void isIncompleteTest() {
	int size { 9 };
	int **inputs = new int*[size] { };
	for (int i = 0; i < size; ++i)
		inputs[i] = new int[size] { };
	Sudoku sudoku(inputs, size);
	for (int i = 0; i < size; ++i)
		delete[] inputs[i];
	delete[] inputs;
	ASSERT_EQUAL(true, sudoku.isIncomplete());
}

void isIncompleteTest2() {
	Sudoku sudoku = sampleSudoku();
	ASSERT_EQUAL(true, sudoku.isIncomplete());
}

void isIncompleteTest3() {
	Sudoku sudoku = completeSudoku();
	ASSERT_EQUAL(false, sudoku.isIncomplete());
}

void isCompleteTest() {
	int size { 9 };
	int **inputs = new int*[size] { };
	for (int i = 0; i < size; ++i)
		inputs[i] = new int[size] { };
	Sudoku sudoku(inputs, size);
	for (int i = 0; i < size; ++i)
		delete[] inputs[i];
	delete[] inputs;
	ASSERT_EQUAL(false, sudoku.isComplete());
}

void isCompleteTest2() {
	Sudoku sudoku = sampleSudoku();
	ASSERT_EQUAL(false, sudoku.isComplete());
}

void isCompleteTest3() {
	Sudoku sudoku = completeSudoku();
	ASSERT_EQUAL(true, sudoku.isComplete());
}

void isCorrectTest() {
	int size { 9 };
	int **inputs = new int*[size] { };
	for (int i = 0; i < size; ++i)
		inputs[i] = new int[size] { };
	Sudoku sudoku(inputs, size);
	for (int i = 0; i < size; ++i)
		delete[] inputs[i];
	delete[] inputs;
	ASSERT_EQUAL(false, sudoku.isCorrect());
}

void isCorrectTest2() {
	Sudoku sudoku = sampleSudoku();
	ASSERT_EQUAL(false, sudoku.isCorrect());
}

void isCorrectTest3() {
	Sudoku sudoku = completeSudoku();
	ASSERT_EQUAL(true, sudoku.isCorrect());
}

void copyConstructorTest() {
	int size { 9 };
	int **inputs = new int*[size] { };
	for (int i = 0; i < size; ++i)
		inputs[i] = new int[size] { };
	Sudoku sudoku(inputs, size);
	for (int i = 0; i < size; ++i)
		delete[] inputs[i];
	delete[] inputs;
	Sudoku copy(sudoku);
	copy.setCell(0,0,1);
	ASSERT_EQUAL(0, sudoku.getCell(0,0));
	ASSERT_EQUAL(1, copy.getCell(0,0));
	std::string msg { "method error in copied object" };
	ASSERT_EQUALM(msg, false, copy.cellIsEmpty(0, 0));
	ASSERT_EQUALM(msg, true, copy.cellIsEmpty(0, 1));
	ASSERT_EQUALM(msg, false, copy.isComplete());
}

void toStringTest() {
	Sudoku sudoku = sampleSudoku();
	std::cout << sudoku.toString();
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
			<< ((float)end - start)/CLOCKS_PER_SEC
			<< "seconds." << std::endl;
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
			<< ((float)end - start)/CLOCKS_PER_SEC
			<< "seconds." << std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void hexadokuTest() {
	Sudoku hexadoku = sampleHexadoku();
	std::cout << hexadoku.toString();
	ASSERT_EQUAL(true, hexadoku.isIncomplete());
	ASSERT_EQUAL(false, hexadoku.isComplete());
	ASSERT_EQUAL(false, hexadoku.isCorrect());
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

void hexadokuPerformanceTest() {
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

void hexadokuFromStringTest() {
	std::string input { ".63B.EC..A..8....847..A6..B....9.....81.D.G...7E.......7..98...CF.D.....AC..2.......D.....E1..5.CE......6...GF.31A.9...B8G7.4..D2.E...45....69.F.7......E..A...5..94..6......D.....63..F79.5...A....E6.D.1...2.8...3G.FA56.......D.C...9...B1.6..2..B.5C9.....34" };
	Sudoku hexadoku(input);
	std::cout << hexadoku.toString();
	ASSERT_EQUAL(true, hexadoku.isIncomplete());
	ASSERT_EQUAL(false, hexadoku.isComplete());
	ASSERT_EQUAL(false, hexadoku.isCorrect());
	ASSERT_EQUAL(0, hexadoku.getCell(0,0));
	ASSERT_EQUAL(6, hexadoku.getCell(0,1));
	ASSERT_EQUAL(11, hexadoku.getCell(0,3));
	ASSERT_EQUAL(4, hexadoku.getCell(15,15));
}

void SudokuBatchSolveTest() {
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

void isEmptyTest() {
	Sudoku sudoku = sampleSudoku();
	ASSERT_EQUAL(false, sudoku.cellIsEmpty(0,0));
	ASSERT_EQUAL(true, sudoku.cellIsEmpty(0,1));
}

void isSafeTest() {
	Sudoku sudoku = sampleSudoku();
	// acceptable number 1, 9 at cell (0,1)
	ASSERT_EQUAL(true, sudoku.isSafe(0,1,1));
	ASSERT_EQUAL(true, sudoku.isSafe(0,1,9));
}

void isSafeTest2() {
	Sudoku sudoku = sampleSudoku();
	// unacceptable number 2, 3, 4, 5, 6, 7, 8 at cell (0,1)
	ASSERT_EQUAL(false, sudoku.isSafe(0,1,2));
	ASSERT_EQUAL(false, sudoku.isSafe(0,1,3));
	ASSERT_EQUAL(false, sudoku.isSafe(0,1,4));
	ASSERT_EQUAL(false, sudoku.isSafe(0,1,5));
	ASSERT_EQUAL(false, sudoku.isSafe(0,1,6));
	ASSERT_EQUAL(false, sudoku.isSafe(0,1,7));
	ASSERT_EQUAL(false, sudoku.isSafe(0,1,8));
	// unacceptable number all at cell (0,0)
	ASSERT_EQUAL(false, sudoku.isSafe(0,0,1));
	ASSERT_EQUAL(false, sudoku.isSafe(0,0,2));
	ASSERT_EQUAL(false, sudoku.isSafe(0,0,3));
	ASSERT_EQUAL(false, sudoku.isSafe(0,0,4));
	ASSERT_EQUAL(false, sudoku.isSafe(0,0,5));
	ASSERT_EQUAL(false, sudoku.isSafe(0,0,6));
	ASSERT_EQUAL(false, sudoku.isSafe(0,0,7));
	ASSERT_EQUAL(false, sudoku.isSafe(0,0,8));
	ASSERT_EQUAL(false, sudoku.isSafe(0,0,9));
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(constructorTest));
	s.push_back(CUTE(setterTest));
	s.push_back(CUTE(getterTest));
	s.push_back(CUTE(isIncompleteTest));
	s.push_back(CUTE(toStringTest));
	s.push_back(CUTE(isIncompleteTest2));
	s.push_back(CUTE(getterTest2));
	s.push_back(CUTE(isCompleteTest2));
	s.push_back(CUTE(isCompleteTest));
	s.push_back(CUTE(isCompleteTest3));
	s.push_back(CUTE(isIncompleteTest3));
	s.push_back(CUTE(isCorrectTest));
	s.push_back(CUTE(isCorrectTest2));
	s.push_back(CUTE(isCorrectTest3));
	s.push_back(CUTE(isEmptyTest));
	s.push_back(CUTE(isSafeTest));
	s.push_back(CUTE(isSafeTest2));
	s.push_back(CUTE(setterTest2));
	s.push_back(CUTE(getterTest3));
	s.push_back(CUTE(copyConstructorTest));
	s.push_back(CUTE(solverTest));
	s.push_back(CUTE(solverTest2));
	s.push_back(CUTE(performanceTest));
	s.push_back(CUTE(performanceTest2));
	s.push_back(CUTE(hexadokuTest));
	s.push_back(CUTE(hexadokuSolverTest));
	s.push_back(CUTE(hexadokuPerformanceTest));
	s.push_back(CUTE(hexadokuFromStringTest));
//	s.push_back(CUTE(SudokuBatchSolveTest));
//	s.push_back(CUTE(hexadokuBatchSolveTest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
