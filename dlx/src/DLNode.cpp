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
#include <cassert>

DLNode::DLNode() { left = right = up = down = column_node = nullptr; }

DLNode::DLNode(int j) {
  left = right = up = down = nullptr;
  number_of_nodes = 0;
  column_node = this;
}

DLNode::DLNode(int i, int j, DLNode *columnNode) {
  left = right = up = down = nullptr;
  row = i;
  column_node = columnNode;
  column_node->number_of_nodes++;
}

DLNode::~DLNode() {
  // TODO Auto-generated destructor stub
}

DLNode *&DLNode::getColumnNode() { return column_node; }

DLNode *&DLNode::getDown() { return down; }

void DLNode::setDown(DLNode *&down) { this->down = down; }

DLNode *&DLNode::getLeft() { return left; }

void DLNode::setLeft(DLNode *&left) { this->left = left; }

DLNode *&DLNode::getRight() { return right; }

void DLNode::setRight(DLNode *&right) { this->right = right; }

int DLNode::getRow() { return row; }

DLNode *&DLNode::getUp() { return up; }

void DLNode::setUp(DLNode *&up) { this->up = up; }

void DLNode::hRemove() {
  assert(this->left->right == this);
  assert(this->right->left == this);
  this->left->right = this->right;
  this->right->left = this->left;
}

void DLNode::vRemove() {
  assert(this->down->up == this);
  assert(this->up->down == this);
  this->down->up = this->up;
  this->up->down = this->down;
  this->column_node->number_of_nodes--;
}

void DLNode::hRestore() {
  this->right->left = this;
  this->left->right = this;
  assert(this->right->left == this);
  assert(this->left->right == this);
}

void DLNode::vRestore() {
  this->up->down = this;
  this->down->up = this;
  this->column_node->number_of_nodes++;
  assert(this->down->up == this);
  assert(this->up->down == this);
}

int DLNode::getNumberOfNode() { return number_of_nodes; }
