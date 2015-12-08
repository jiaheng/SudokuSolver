#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Sudoku.h"
#include "SudokuSolver.h"

Sudoku<9> sampleSudoku() {
	std::array<std::array<int,9>,9> inputs {{
		{{3, 0, 6, 5, 0, 8, 4, 0, 0}},
		{{5, 2, 0, 0, 0, 0, 0, 0, 0}},
		{{0, 8, 7, 0, 0, 0, 0, 3, 1}},
		{{0, 0, 3, 0, 1, 0, 0, 8, 0}},
		{{9, 0, 0, 8, 6, 3, 0, 0, 5}},
		{{0, 5, 0, 0, 9, 0, 6, 0, 0}},
		{{1, 3, 0, 0, 0, 0, 2, 5, 0}},
		{{0, 0, 0, 0, 0, 0, 0, 7, 4}},
		{{0, 0, 5, 2, 0, 6, 3, 0, 0}}
	}};
	Sudoku<9> sudoku(inputs);
	return sudoku;
}

Sudoku<9> sampleSudoku2() {
	std::array<std::array<int,9>,9> inputs {{
		{{9, 0, 0, 0, 4, 0, 0, 0, 0}},
		{{7, 0, 0, 2, 0, 0, 0, 9, 0}},
		{{0, 0, 0, 0, 1, 0, 4, 3, 0}},
		{{0, 6, 0, 0, 0, 3, 0, 2, 0}},
		{{4, 0, 0, 0, 5, 0, 0, 0, 7}},
		{{0, 9, 0, 4, 0, 0, 0, 8, 0}},
		{{0, 8, 4, 0, 6, 0, 0, 0, 0}},
		{{0, 7, 0, 0, 0, 5, 0, 0, 1}},
		{{0, 0, 0, 0, 2, 0, 0, 0, 6}}
	}};
	Sudoku<9> sudoku(inputs);
	return sudoku;
}

Sudoku<9> completeSudoku() {
	std::array<std::array<int,9>,9> inputs {{
		{{3, 1, 6, 5, 7, 8, 4, 9, 2}},
		{{5, 2, 9, 1, 3, 4, 7, 6, 8}},
		{{4, 8, 7, 6, 2, 9, 5, 3, 1}},
		{{2, 6, 3, 4, 1, 5, 9, 8, 7}},
		{{9, 7, 4, 8, 6, 3, 1, 2, 5}},
		{{8, 5, 1, 7, 9, 2, 6, 4, 3}},
		{{1, 3, 8, 9, 4, 7, 2, 5, 6}},
		{{6, 9, 2, 3, 5, 1, 8, 7, 4}},
		{{7, 4, 5, 2, 8, 6, 3, 1, 9}}
	}};
	Sudoku<9> sudoku(inputs);
	return sudoku;
}

Sudoku<16> sampleHexadoku() {
	std::array<std::array<int,16>,16> inputs {{
		{{4, 3, 7, 11, 14, 0, 13, 2, 16, 10, 0, 8, 0, 9, 0, 15}},
		{{6, 0, 0, 1, 5, 8, 9, 0, 13, 0, 2, 0, 10, 0, 4, 0}},
		{{2, 0, 9, 10, 0, 6, 0, 0, 0, 5, 3, 0, 0, 0, 0, 0}},
		{{14, 13, 0, 5, 0, 0, 10, 4, 7, 1, 9, 0, 0, 0, 8, 12}},
		{{9, 0, 10, 4, 1, 11, 3, 5, 8, 2, 12, 6, 13, 15, 0, 0}},
		{{0, 11, 2, 12, 0, 9, 16, 0, 10, 0, 14, 0, 0, 0, 0, 0}},
		{{1, 5, 0, 0, 10, 2, 0, 8, 0, 11, 4, 13, 9, 0, 0, 0}},
		{{0, 6, 8, 0, 13, 0, 0, 12, 0, 9, 0, 16, 11, 0, 0, 0}},
		{{0, 0, 0, 6, 3, 0, 2, 0, 1, 0, 0, 12, 0, 14, 15, 0}},
		{{0, 0, 0, 2, 8, 14, 12, 0, 11, 0, 15, 3, 0, 0, 10, 9}},
		{{0, 0, 0, 0, 0, 13, 0, 7, 0, 6, 8, 0, 3, 12, 1, 0}},
		{{0, 0, 13, 14, 11, 15, 1, 6, 9, 7, 5, 10, 4, 8, 0, 2}},
		{{7, 1, 0, 0, 0, 10, 8, 13, 4, 12, 0, 0, 15, 0, 3, 6}},
		{{0, 0, 0, 0, 0, 16, 5, 0, 0, 0, 10, 0, 8, 1, 0, 4}},
		{{0, 4, 0, 15, 0, 7, 0, 3, 0, 8, 1, 9, 14, 0, 0, 10}},
		{{11, 0, 3, 0, 4, 0, 15, 14, 6, 16, 0, 5, 12, 2, 9, 7}}
	}};
	Sudoku<16> sudoku(inputs);
	return sudoku;
}

void constructorTest() {
	std::array<std::array<int,9>,9> inputs {};
	Sudoku<9> sudoku(inputs);
}

void setterTest() {
	int size { 9 };
	std::array<std::array<int,9>,9> inputs {};
	Sudoku<9> sudoku(inputs);
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
	std::array<std::array<int,16>,16> inputs {};
	Sudoku<16> sudoku(inputs);
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
	std::array<std::array<int,9>,9> inputs {};
	Sudoku<9> sudoku(inputs);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			int cond = sudoku.getCell(i, j);
			ASSERT_EQUAL(0, cond);
		}
}

void getterTest2() {
	int size { 16 };
	std::array<std::array<int,16>,16> inputs {};
	Sudoku<16> sudoku(inputs);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			int cond = sudoku.getCell(i, j);
			ASSERT_EQUAL(0, cond);
		}
}

void getterTest3() {
	Sudoku<9> sudoku = sampleSudoku();
	ASSERT_EQUAL(3, sudoku.getCell(0,0));
}

void isIncompleteTest() {
	std::array<std::array<int,9>,9> inputs {};
	Sudoku<9> sudoku(inputs);
	ASSERT_EQUAL(true, sudoku.isIncomplete());
}

void isIncompleteTest2() {
	Sudoku<9> sudoku = sampleSudoku();
	ASSERT_EQUAL(true, sudoku.isIncomplete());
}

void isIncompleteTest3() {
	Sudoku<9> sudoku = completeSudoku();
	ASSERT_EQUAL(false, sudoku.isIncomplete());
}

void isCompleteTest() {
	std::array<std::array<int,9>,9> inputs {};
	Sudoku<9> sudoku(inputs);
	ASSERT_EQUAL(false, sudoku.isComplete());
}

void isCompleteTest2() {
	Sudoku<9> sudoku = sampleSudoku();
	ASSERT_EQUAL(false, sudoku.isComplete());
}

void isCompleteTest3() {
	Sudoku<9> sudoku = completeSudoku();
	ASSERT_EQUAL(true, sudoku.isComplete());
}

void isCorrectTest() {
	std::array<std::array<int,9>,9> inputs {};
	Sudoku<9> sudoku(inputs);
	ASSERT_EQUAL(false, sudoku.isCorrect());
}

void isCorrectTest2() {
	Sudoku<9> sudoku = sampleSudoku();
	ASSERT_EQUAL(false, sudoku.isCorrect());
}

void isCorrectTest3() {
	Sudoku<9> sudoku = completeSudoku();
	ASSERT_EQUAL(true, sudoku.isCorrect());
}

void copyConstructorTest() {
	std::array<std::array<int,9>,9> inputs {};
	Sudoku<9> sudoku(inputs);
	Sudoku<9> copy(sudoku);
	copy.setCell(0,0,1);
	ASSERT_EQUAL(0, sudoku.getCell(0,0));
	ASSERT_EQUAL(1, copy.getCell(0,0));
}

void toStringTest() {
	Sudoku<9> sudoku = sampleSudoku();
	std::cout << sudoku.toString();
}

void solverTest() {
	Sudoku<9> sudoku = sampleSudoku();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver<9> solver(sudoku);
	Sudoku<9> solution = solver.getSolution();
	std::cout << "\nAfter:\n";
	std::cout << solution.toString();
	ASSERT_EQUAL(true, solution.isCorrect());
}

void performanceTest() {
	Sudoku<9> sudoku = sampleSudoku();
	SudokuSolver<9> solver(sudoku);
	int start = clock();
	Sudoku<9> solution = solver.getSolution();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float)end - start)/CLOCKS_PER_SEC
			<< "seconds." << std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void solverTest2() {
	Sudoku<9> sudoku = sampleSudoku2();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver<9> solver(sudoku);
	Sudoku<9> solution = solver.getSolution();
	std::cout << "\nAfter:\n";
	std::cout << solution.toString();
	ASSERT_EQUAL(true, solution.isCorrect());
}

void performanceTest2() {
	Sudoku<9> sudoku = sampleSudoku2();
	SudokuSolver<9> solver(sudoku);
	int start = clock();
	Sudoku<9> solution = solver.getSolution();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float)end - start)/CLOCKS_PER_SEC
			<< "seconds." << std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void hexadokuTest() {
	Sudoku<16> hexadoku = sampleHexadoku();
	std::cout << hexadoku.toString();
	ASSERT_EQUAL(true, hexadoku.isIncomplete());
	ASSERT_EQUAL(false, hexadoku.isComplete());
	ASSERT_EQUAL(false, hexadoku.isCorrect());
}

void hexadokuSolverTest() {
	Sudoku<16> sudoku = sampleHexadoku();
	std::cout << "Before:\n";
	std::cout << sudoku.toString();
	SudokuSolver<16> solver(sudoku);
	Sudoku<16> solution = solver.getSolution();
	std::cout << "\nAfter:\n";
	std::cout << solution.toString();
	ASSERT_EQUAL(true, solution.isCorrect());
}

void hexadokuPerformanceTest() {
	Sudoku<16> sudoku = sampleHexadoku();
	SudokuSolver<16> solver(sudoku);
	int start = clock();
	Sudoku<16> solution = solver.getSolution();
	int end = clock();
	std::cout << "it took " << end - start << "ticks, or "
			<< ((float)end - start)/CLOCKS_PER_SEC
			<< "seconds." << std::endl;
	ASSERT_EQUAL(true, solution.isCorrect());
}

void hexadokuFromStringTest() {
	std::string input { ".63B.EC..A..8....847..A6..B....9.....81.D.G...7E.......7..98...CF.D.....AC..2.......D.....E1..5.CE......6...GF.31A.9...B8G7.4..D2.E...45....69.F.7......E..A...5..94..6......D.....63..F79.5...A....E6.D.1...2.8...3G.FA56.......D.C...9...B1.6..2..B.5C9.....34" };
	Sudoku<16> hexadoku(input);
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
	std::vector<Sudoku<9>> puzzles { };
	while (std::getline(infile, line)) {
		// read file line by line
	    std::istringstream iss(line);
	    puzzles.push_back(Sudoku<9>(line));
	}
	int index {1};
	int time {0};
	for (auto &hexadoku: puzzles) {
		std::cout << "Solving puzzle #" << index << "..." << std::endl;
		SudokuSolver<9> solver(hexadoku);
		int start = clock();
		Sudoku<9> solution = solver.getSolution();
		int end = clock();
		time += end - start;
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
	std::vector<Sudoku<16>> puzzles { };
	while (std::getline(infile, line)) {
		// read file line by line
	    std::istringstream iss(line);
	    puzzles.push_back(Sudoku<16>(line));
	}
	int index {1};
	for (auto &hexadoku: puzzles) {
		std::cout << "Solving puzzle #" << index << "..." << std::endl;
		std::cout << hexadoku.toString() << std::endl;
		SudokuSolver<16> solver(hexadoku);
		Sudoku<16> solution = solver.getSolution();
		std::string msg {"Solution for puzzle #"};
		msg += index;
		msg += " is not correct.";
		ASSERT_EQUALM(msg, true, solution.isCorrect());
		index++;
	}
}

void hexadokuPerformanceBatchTest() {

}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(constructorTest));
	s.push_back(CUTE(setterTest));
	s.push_back(CUTE(getterTest));
	s.push_back(CUTE(isIncompleteTest));
	s.push_back(CUTE(copyConstructorTest));
	s.push_back(CUTE(toStringTest));
	s.push_back(CUTE(isIncompleteTest2));
	s.push_back(CUTE(getterTest2));
	s.push_back(CUTE(isCompleteTest2));
	s.push_back(CUTE(isCompleteTest));
	s.push_back(CUTE(isCompleteTest3));
	s.push_back(CUTE(isIncompleteTest3));
	s.push_back(CUTE(solverTest));
	s.push_back(CUTE(performanceTest));
	s.push_back(CUTE(solverTest2));
	s.push_back(CUTE(performanceTest2));
	s.push_back(CUTE(isCorrectTest));
	s.push_back(CUTE(isCorrectTest2));
	s.push_back(CUTE(isCorrectTest3));
	s.push_back(CUTE(setterTest2));
	s.push_back(CUTE(getterTest3));
	s.push_back(CUTE(hexadokuTest));
	s.push_back(CUTE(hexadokuSolverTest));
	s.push_back(CUTE(hexadokuPerformanceTest));
	s.push_back(CUTE(hexadokuFromStringTest));
	//s.push_back(CUTE(hexadokuBatchSolveTest));
	s.push_back(CUTE(SudokuBatchSolveTest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
