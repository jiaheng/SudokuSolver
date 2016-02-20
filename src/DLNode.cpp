/*
 * Copyright (c) 2015 Jia Heng Eik
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * DLNode.cpp
 *
 *  Created on: 12 Feb 2016
 *      Author: jiaheng
 */

#include "DLNode.hpp"

DLNode::DLNode() {
	left = right = up = down = column_node = nullptr;
}

DLNode::DLNode(int i, int j) {
	left = right = up = down = column_node = nullptr;
	row = i;
	col = j;
}

DLNode::~DLNode() {
	// TODO Auto-generated destructor stub
}

int DLNode::getCol()  {
	return col;
}

DLNode*& DLNode::getColumnNode() {
	return column_node;
}

void DLNode::setColumnNode(DLNode*& columnNode) {
	column_node = columnNode;
}

 DLNode*& DLNode::getDown()  {
	return down;
}

void DLNode::setDown( DLNode*& down) {
	this->down = down;
}

 DLNode*& DLNode::getLeft()  {
	return left;
}

void DLNode::setLeft( DLNode*& left) {
	this->left = left;
}

 DLNode*& DLNode::getRight()  {
	return right;
}

void DLNode::setRight( DLNode*& right) {
	this->right = right;
}

int DLNode::getRow()  {
	return row;
}

 DLNode*& DLNode::getUp()  {
	return up;
}

void DLNode::setUp(DLNode*& up) {
	this->up = up;
}

void DLNode::hRemove() {
	this->left->right = this->right;
	this->right->left = this->left;
}

void DLNode::vRemove() {
	this->down->up = this->up;
	this->up->down = this->down;
}

void DLNode::hRestore() {
	this->right->left = this;
	this->left->right = this;
}

void DLNode::vRestore() {
	this->up->down = this;
	this->down->up = this;
}
