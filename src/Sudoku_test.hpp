/*
 * Sudoku_test.hpp
 *
 *  Created on: 15 Feb 2016
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKU_TEST_HPP_
#define SRC_SUDOKU_TEST_HPP_

#include "cute.h"
#include "Sudoku.hpp"

class Sudoku_test {
public:
	Sudoku_test();
	void operator()();
	static cute::suite make_suite();

private:
	void constructorTest();
	void setterTest();
	void getterTest();
	void isIncompleteTest();
	void toStringTest();
	void isIncompleteTest2();
	void getterTest2();
	void isCompleteTest2();
	void isCompleteTest();
	void isCompleteTest3();
	void isIncompleteTest3();
	void isCorrectTest();
	void isCorrectTest2();
	void isCorrectTest3();
	void isEmptyTest();
	void isSafeTest();
	void isSafeTest2();
	void setterTest2();
	void getterTest3();
	void copyConstructorTest();
	void hexadokuTest();
	void hexadokuFromStringTest();
	Sudoku sampleSudoku();
    Sudoku sampleSudoku2();
    Sudoku completeSudoku();
    Sudoku sampleHexadoku();

};

#endif /* SRC_SUDOKU_TEST_HPP_ */
