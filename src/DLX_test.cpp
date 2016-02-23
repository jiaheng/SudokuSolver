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

std::vector<std::vector <int>> multiSolutionMatrix() {
	/*
	 * 0 0 0 0 0 1	[1]	[2]
	 * 0 0 0 0 0 1 	[duplicate]
	 * 0 0 0 1 0 0	[1]
	 * 0 1 0 0 0 0	[1]
	 * 1 0 0 0 0 0  [1]	[2]
	 * 0 1 1 0 0 0		[2]
	 * 0 0 1 0 0 0	[1]
	 * 0 0 0 0 1 0	[1]
	 * 0 0 0 1 1 0		[2]
	 * 1 0 0 0 0 0	[duplicate]
	 * 1 0 0 0 0 0	[duplicate]
	 * 0 1 0 0 0 0	[duplicate]
	 */
	std::vector<std::vector <int>> matrix { };
	matrix.push_back({0, 0, 0, 0, 0, 1});
	matrix.push_back({0, 0, 0, 0, 0, 1});
	matrix.push_back({0, 0, 0, 1, 0, 0});
	matrix.push_back({0, 1, 0, 0, 0, 0});
	matrix.push_back({1, 0, 0, 0, 0, 0});
	matrix.push_back({0, 1, 1, 0, 0, 0});
	matrix.push_back({0, 0, 1, 0, 0, 0});
	matrix.push_back({0, 0, 0, 0, 1, 0});
	matrix.push_back({0, 0, 0, 1, 1, 0});
	matrix.push_back({1, 0, 0, 0, 0, 0});
	matrix.push_back({1, 0, 0, 0, 0, 0});
	matrix.push_back({0, 1, 0, 0, 0, 0});
	return matrix;
}

void dLXConstructorTest() {
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

void multiSolutionTest() {
	auto matrix = multiSolutionMatrix();
	DLX dlx {matrix};
	dlx.solve();
	auto result = dlx.getSolution();
	ASSERTM("No solution found!!!", result.size() > 0);
	std::vector<int> matrix_check { };
	matrix_check.resize(matrix[0].size());
	for (auto index : result) {
		for (unsigned i = 0; i < matrix[index].size(); ++i) {
			if (matrix[index][i] == 1) {
				ASSERTM("Conflict at " + std::to_string(index) + " found!!!", matrix[index][i] != matrix_check[i]);
				matrix_check[i] = matrix[index][i];
			}
		}
	}
}

std::vector<std::vector <int>> noSolutionMatrix() {
	/*
	 * 0 0 0 0 0 0 1	[1]	[2]
	 * 0 0 0 0 0 0 1 	[duplicate]
	 * 0 0 0 0 1 0 0	[1]
	 * 0 0 1 0 0 0 0	[1]
	 * 0 1 0 0 0 0 0  [1]	[2]
	 * 0 0 1 1 0 0 0		[2]
	 * 0 0 0 1 0 0 0	[1]
	 * 0 0 0 0 0 1 0	[1]
	 * 0 0 0 0 1 1 0		[2]
	 * 0 1 0 0 0 0 0	[duplicate]
	 * 0 1 0 0 0 0 0	[duplicate]
	 * 0 0 1 0 0 0 0	[duplicate]
	 */
	std::vector<std::vector <int>> matrix { };
	matrix.push_back({0, 0, 0, 0, 0, 0, 1});
	matrix.push_back({0, 0, 0, 0, 0, 0, 1});
	matrix.push_back({0, 0, 0, 0, 1, 0, 0});
	matrix.push_back({0, 0, 1, 0, 0, 0, 0});
	matrix.push_back({0, 1, 0, 0, 0, 0, 0});
	matrix.push_back({0, 0, 1, 1, 0, 0, 0});
	matrix.push_back({0, 0, 0, 1, 0, 0, 0});
	matrix.push_back({0, 0, 0, 0, 0, 1, 0});
	matrix.push_back({0, 0, 0, 0, 1, 1, 0});
	matrix.push_back({0, 1, 0, 0, 0, 0, 0});
	matrix.push_back({0, 1, 0, 0, 0, 0, 0});
	matrix.push_back({0, 0, 1, 0, 0, 0, 0});
	return matrix;
}

void noSolutionTest() {
	auto matrix = noSolutionMatrix();
	DLX dlx {matrix};
	ASSERT(!dlx.solve());
	auto result = dlx.getSolution();
	ASSERTM("Expected no solution (size ==0)!!!", result.size() == 0);
}

cute::suite make_suite_DLX_test() {
	cute::suite s;
	s.push_back(CUTE(dLXConstructorTest));
	s.push_back(CUTE(solveTest));
	s.push_back(CUTE(multiSolutionTest));
	s.push_back(CUTE(noSolutionTest));
	return s;
}

