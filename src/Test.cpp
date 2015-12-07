#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Sudoku.h"
#include "SudokuSolver.h"

Sudoku sampleSudoku() {
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
	Sudoku sudoku(inputs);
	return sudoku;
}

Sudoku sampleSudoku2() {
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
	Sudoku sudoku(inputs);
	return sudoku;
}

Sudoku completeSudoku() {
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
	Sudoku sudoku(inputs);
	return sudoku;
}

void constructorTest() {
	std::array<std::array<int,9>,9> inputs {};
	Sudoku sudoku(inputs);
}

void setterTest() {
	std::array<std::array<int,9>,9> inputs {};
	Sudoku sudoku(inputs);
	sudoku.setCell(0,0,1);
	int cond = sudoku.getCell(0,0);
	ASSERT_EQUAL(1, cond);
	for (int j = 1; j < 9; j++) {
		int cond = sudoku.getCell(0, j);
		ASSERT_EQUAL(0, cond);
	}
	for (int i = 1; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			int cond = sudoku.getCell(i, j);
			ASSERT_EQUAL(0, cond);
		}
}

void getterTest() {
	std::array<std::array<int,9>,9> inputs {};
	Sudoku sudoku(inputs);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			int cond = sudoku.getCell(i, j);
			ASSERT_EQUAL(0, cond);
		}
}

void getterTest2() {
	Sudoku sudoku = sampleSudoku();
	ASSERT_EQUAL(3, sudoku.getCell(0,0));
}

void isIncompleteTest() {
	std::array<std::array<int,9>,9> inputs {};
	Sudoku sudoku(inputs);
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
	std::array<std::array<int,9>,9> inputs {};
	Sudoku sudoku(inputs);
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
	std::array<std::array<int,9>,9> inputs {};
	Sudoku sudoku(inputs);
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
	std::array<std::array<int,9>,9> inputs {};
	Sudoku sudoku(inputs);
	Sudoku copy(sudoku);
	copy.setCell(0,0,1);
	ASSERT_EQUAL(0, sudoku.getCell(0,0));
	ASSERT_EQUAL(1, copy.getCell(0,0));
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
	std::cout << solution.toString();
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
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



