/*
 * DLNode.hpp
 *
 *  Created on: 12 Feb 2016
 *      Author: jiaheng
 */

#ifndef SRC_DLNODE_HPP_
#define SRC_DLNODE_HPP_

class DLNode
{
public:
    DLNode();                                 // for head
    DLNode(int col);                          // for column nodes
    DLNode(int row, int col, DLNode* column); // for nodes
    ~DLNode();

    DLNode*& getColumnNode();
    DLNode*& getDown();
    void setDown(DLNode*& down);
    DLNode*& getLeft();
    void setLeft(DLNode*& left);
    DLNode*& getRight();
    void setRight(DLNode*& right);
    int getRow();
    DLNode*& getUp();
    void setUp(DLNode*& up);
    int getNumberOfNode();

    void hRemove();  // remove horizontally
    void vRemove();  // remove vertically
    void hRestore(); // restore horizontally
    void vRestore(); // restore vertically

private:
    DLNode *left, *right, *up, *down, *column_node;
    union {
        int row;
        int number_of_nodes;
    };
};

#endif /* SRC_DLNODE_HPP_ */
