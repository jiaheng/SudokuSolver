#include "DLX_test.hpp"
#include "DLX.hpp"
#include <vector>
#include "cute.h"
#include <iostream>

void constructorTest() {
	std::vector<std::vector <int>> matrix { };
	std::vector<int> row {0, 1, 0};
	matrix.push_back(row);
	row = {1, 1, 1};
	matrix.push_back(row);
	row = {1, 0, 0};
	matrix.push_back(row);
	row = {0, 0, 1};
	matrix.push_back(row);
	DLX dlx {matrix};
	std::cout << "print toString()" << std::endl;
	std::cout << dlx.toString() << std::endl;
	ASSERT(true);
}

cute::suite make_suite_DLX_test(){
	cute::suite s;
	s.push_back(CUTE(constructorTest));
	return s;
}



