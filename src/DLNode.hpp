/*
 * DLNode.hpp
 *
 *  Created on: 12 Feb 2016
 *      Author: jiaheng
 */

#ifndef SRC_DLNODE_HPP_
#define SRC_DLNODE_HPP_

class DLNode {
public:
	DLNode();
	~DLNode();
	DLNode *left, *right, *up, *down, *column_node;
	int row{}, col{};
};

#endif /* SRC_DLNODE_HPP_ */
