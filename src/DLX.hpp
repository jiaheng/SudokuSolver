/*
 * DLX.hpp
 *
 *  Created on: 12 Feb 2016
 *      Author: jiaheng
 */

#ifndef SRC_DLX_HPP_
#define SRC_DLX_HPP_

#include <string>
#include <vector>
#include "DLNode.hpp"

class DLX {
public:
	DLX(std::vector<std::vector <int>> matrix);
	~DLX();

	std::string toString();
	bool solve();
	std::vector<int> getSolution();

private:
	std::vector<int> solution { };
	DLNode *head {nullptr};

	DLX() {}

	void cover(DLNode *node);
	void uncover(DLNode *node);
	DLNode *chooseNextColumn();
	int totalNode(DLNode *column);
};

#endif /* SRC_DLX_HPP_ */
