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
	void testCover();
	void testUncover();
	DLNode *testnode {nullptr};

private:
	DLX() {}
	DLNode *head {nullptr};

	void cover(DLNode *node);
	void uncover(DLNode *node);
	DLNode *chooseNextColumn();
};

#endif /* SRC_DLX_HPP_ */
