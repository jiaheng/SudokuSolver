#include "DLX_test.hpp"
#include "DLX.hpp"
#include <vector>
#include "cute.h"
#include <iostream>

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

void coverTest() {
	std::vector<std::vector<int>> matrix = sampleMatrix();
	DLX dlx { matrix };
	std::cout << "before cover:" << std::endl;
	std::cout << dlx.toString() << std::endl;
	dlx.testCover();
	std::cout << "after cover:" << std::endl << dlx.toString() << std::endl;
	ASSERT(true);
}

void unCoverTest() {
	std::vector<std::vector<int>> matrix = sampleMatrix();
	DLX dlx { matrix };
	std::cout << "before cover:" << std::endl;
	std::cout << dlx.toString() << std::endl;
	dlx.testCover();
	std::cout << "after cover:" << std::endl << dlx.toString() << std::endl;
	dlx.testUncover();
	std::cout << "after uncover:" << std::endl << dlx.toString() << std::endl;
	ASSERT(true);
}

cute::suite make_suite_DLX_test() {
	cute::suite s;
	s.push_back(CUTE(constructorTest));
	s.push_back(CUTE(coverTest));
	s.push_back(CUTE(unCoverTest));
	return s;
}

