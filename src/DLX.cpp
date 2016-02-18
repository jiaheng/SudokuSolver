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
 * DLX.cpp
 *
 *  Created on: 12 Feb 2016
 *      Author: jiaheng
 */

#include <iostream>

#include "DLX.hpp"

DLX::DLX(std::vector<std::vector <int>> matrix) {
	const int col_size = matrix[0].size();
	head = new DLNode{ };
	std::vector<DLNode*> temp_col_ptr { };
	std::vector<DLNode*> head_col_ptr { };
	DLNode *node_ptr = head;
	// create column node
	for (int i = 0; i < col_size; ++i) {
		auto *node = new DLNode{ 0, i };
		node_ptr->setRight(node);
		node->setLeft(node_ptr);
		node->setColumnNode(node);
		node_ptr = node;
		temp_col_ptr.push_back(node);
		head_col_ptr.push_back(node);
	}
	node_ptr->setRight(head);
	head->setLeft(node_ptr);

	// create nodes for matrix
	const int row_size = matrix.size();
	for (int i = 0; i < row_size; ++i) {
		DLNode *temp_row_ptr{nullptr},
				*head_row_ptr{nullptr};
		for (int j = 0; j < col_size; ++j) {
			if (matrix[i][j] == 1) {
				auto *node = new DLNode { i, j };
				node->setColumnNode(head_col_ptr[j]);
				temp_col_ptr[j]->setDown(node);
				node->setUp(temp_col_ptr[j]);
				temp_col_ptr[j] = node;
				if (temp_row_ptr) {
					temp_row_ptr->setRight(node);
					node->setLeft(temp_row_ptr);
					temp_row_ptr = node;
				} else
					temp_row_ptr = head_row_ptr = node;
			}
		}
		temp_row_ptr->setRight(head_row_ptr);
		head_row_ptr->setLeft(temp_row_ptr);
	}
	for (int i = 0; i < col_size; ++i) {
		temp_col_ptr[i]->setDown(head_col_ptr[i]);
		head_col_ptr[i]->setUp(temp_col_ptr[i]);
	}
}

DLX::~DLX() {
	while (head->getRight() != head) {
		DLNode *col_node = head->getRight();
		while (col_node->getDown() != col_node) {
			DLNode *node = col_node->getDown();
			node->vRemove();
			delete node;
		}
		col_node->hRemove();
		delete col_node;
	}
	delete head;
}

std::string DLX::toString() {
	std::string str { };
	std::vector<std::vector<int>> matrix { };
	int max_row { 0 }, max_col { 0 };
	DLNode *col_ptr = head->getRight();
	while (col_ptr != head) {
		DLNode *node = col_ptr->getDown();
		while (node != col_ptr) {
			int row = node->getRow();
			int col = node->getCol();
			if (max_row <= row) {
				max_row = row + 1;
				matrix.resize(max_row);
			}
			if (max_col <= col) max_col = col + 1;
			matrix[row].resize(max_col);
			matrix[row][col] = 1;
			node = node->getDown();
		}
		col_ptr = col_ptr->getRight();
	}
	for (auto row : matrix) {
		row.resize(max_col);
		for (auto cell : row) {
			str += std::to_string(cell) + " ";
		}
		str += "\n";
	}
	return str;
}

void DLX::cover(DLNode *node) {
	DLNode *column = node->getColumnNode();
	column->hRemove();
	for (auto *row = column->getDown(); row != column; row = row->getDown()) {
		for (auto rightNode = row->getRight(); rightNode != row; rightNode = rightNode->getRight()) {
			rightNode->vRemove();
		}
	}
}

void DLX::uncover(DLNode* node) {
	DLNode *column = node->getColumnNode();
	for (auto *row = column->getUp(); row != column; row = row->getUp()) {
		for (auto leftNode = row->getLeft(); leftNode != row; leftNode = leftNode->getLeft()) {
			leftNode->vRestore();
		}
	}
	column->hRestore();
}

DLNode *DLX::chooseNextColumn() {
	int min_num { 0 }; // minimum number of node in a column
	DLNode *column = head->getRight(),
			*next_col = column;
	while (column != head) {
		int node_num = totalNode(column);
		if (node_num <= 1) return column;
		else if (min_num == 0 || node_num < min_num) {
			min_num = node_num;
			next_col = column;
		}
		column = column->getRight();
	}
	return next_col;
}

int DLX::totalNode(DLNode *column) {
	int node_num { 0 };
	DLNode *node = column->getDown();
	while (node != column) {
		++node_num;
		node = node->getDown();
	}
	return node_num;
}

bool DLX::solve() {
	if (head->getRight() == head) return true;
	DLNode *column = chooseNextColumn();
	cover(column);
	for (auto row = column->getDown(); row != column; row = row->getDown()) {
		solution.push_back(row->getRow());
		for (auto rightNode = row->getRight(); rightNode != row; rightNode = rightNode->getRight())
			cover(rightNode);
		if (solve()) return true;
		solution.pop_back();
		for (auto rightNode = row->getRight(); rightNode != row; rightNode = rightNode->getRight())
			uncover(rightNode);
	}
	uncover(column);
	return false;
}

std::vector<int> DLX::getSolution() {
	return solution;
}
