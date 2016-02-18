#include "DLX_test.hpp"
#include "DLX.hpp"
#include "DLNode.hpp"
#include <vector>
#include "cute.h"
#include <iostream>
#include <algorithm>

std::vector<std::vector <int>> sampleMatrix() {
	std::vector<std::vector <int>> matrix { };
	std::vector<int> row { };
	row = {0, 1, 0, 1, 1, 0};
	matrix.push_back(row);
	row = {1, 1, 0, 0, 1, 0};
	matrix.push_back(row);
	row = {1, 0, 0, 0, 0, 1};
	matrix.push_back(row);
	row = {0, 0, 1, 1, 0, 1};
	matrix.push_back(row);
	return matrix;
}

std::vector<std::vector <int>> problemMatrix() {
	/*
	 * 0 0 1 0 1 1 0
	 * 1 0 0 1 0 0 1
	 * 0 1 1 0 0 1 0
	 * 1 0 0 1 0 0 0
	 * 0 1 0 0 0 0 1
	 * 0 0 0 1 1 0 1
	 */
	std::vector<std::vector <int>> matrix { };
	std::vector<int> row { };
	row = {0, 0, 1, 0, 1, 1, 0};
	matrix.push_back(row);
	row = {1, 0, 0, 1, 0, 0, 1};
	matrix.push_back(row);
	row = {0, 1, 1, 0, 0, 1, 0};
	matrix.push_back(row);
	row = {1, 0, 0, 1, 0, 0, 0};
	matrix.push_back(row);
	row = {0, 1, 0, 0, 0, 0, 1};
	matrix.push_back(row);
	row = {0, 0, 0, 1, 1, 0, 1};
	matrix.push_back(row);
	return matrix;
}

void constructorTest() {
	std::vector<std::vector<int>> matrix { };
	std::vector<int> row { 0, 1, 0 };
	matrix.push_back(row);
	row = {1, 1, 1};
	matrix.push_back(row);
	row = {1, 0, 0};
	matrix.push_back(row);
	row = {0, 0, 1};
	matrix.push_back(row);
	DLX dlx { matrix };
	std::cout << "print toString()" << std::endl;
	std::cout << dlx.toString() << std::endl;
	ASSERT(true);
}

void solveTest() {
	auto matrix = problemMatrix();
	DLX dlx {matrix };
	dlx.solve();
	auto result = dlx.getSolution();
	ASSERT_EQUALM("Solution size not Equal", 3, result.size());
	std::vector<int>::iterator it = std::find(result.begin(), result.end(), 0);
	ASSERTM("Solution does not contain 0", it != result.end());
	it = std::find(result.begin(), result.end(), 3);
	ASSERTM("Solution does not contain 3", it != result.end());
	it = std::find(result.begin(), result.end(), 4);
	ASSERTM("Solution does not contain 4", it != result.end());
}

cute::suite make_suite_DLX_test() {
	cute::suite s;
	s.push_back(CUTE(constructorTest));
	s.push_back(CUTE(solveTest));
	return s;
}

