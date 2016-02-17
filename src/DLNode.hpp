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
	DLNode(int row, int col);
	~DLNode();

	int getCol() ;
	DLNode*& getColumnNode();
	void setColumnNode(DLNode*& columnNode);
	 DLNode*& getDown() ;
	void setDown( DLNode*& down);
	 DLNode*& getLeft() ;
	void setLeft( DLNode*& left);
	 DLNode*& getRight() ;
	void setRight( DLNode*& right);
	int getRow() ;
	 DLNode*& getUp() ;
	void setUp(DLNode*& up);

	void hRemove(); // remove horizontally
	void vRemove(); // remove vertically
	void hRestore(); // restore horizontally
	void vRestore(); // restore vertically

private:
	DLNode *left, *right, *up, *down, *column_node;
	int row{}, col{};
};

#endif /* SRC_DLNODE_HPP_ */
