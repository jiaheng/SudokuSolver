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

#include "DLX.hpp"

DLX::DLX(std::vector<std::vector <int>> matrix) {
	const int col_size = matrix[0].size();
	head = new DLNode{ };
	std::vector<DLNode*> temp_col_ptr { };
	std::vector<DLNode*> head_col_ptr { };
	DLNode *node_ptr = head;
	for (int i = 0; i < col_size; ++i) {
		DLNode *node = new DLNode{ };
		node_ptr->right = node;
		node->left = node_ptr;
		node_ptr = node;
		temp_col_ptr.push_back(node);
		head_col_ptr.push_back(node);
	}
	node_ptr->right = head;
	head->left = node_ptr;
	const int row_size = matrix.size();
	for (int i = 0; i < row_size; ++i) {
		DLNode *temp_row_ptr{nullptr}, *head_row_ptr{nullptr};
		for (int j = 0; j < col_size; ++j) {
			if (matrix[i][j] == 1) {
				DLNode *node = new DLNode{ };
				node->row = i;
				node->col = j;
				node->column_node = head_col_ptr[j];
				temp_col_ptr[j]->down = node;
				node->up = temp_col_ptr[j];
				temp_col_ptr[j] = node;
				if (temp_row_ptr) {
					temp_row_ptr->right = node;
					node->left = temp_row_ptr;
					temp_row_ptr = node;
				} else
					temp_row_ptr = head_row_ptr = node;
			}
		}
		temp_row_ptr->right = head_row_ptr;
		head_row_ptr->left = temp_row_ptr;
	}
	for (int i = 0; i < col_size; ++i) {
		temp_col_ptr[i]->down = head_col_ptr[i];
		head_col_ptr[i]->up = temp_col_ptr[i];
	}
}

DLX::~DLX() {
	while (head->right != head) {
		DLNode *col_node = head->right;
		while (col_node->down != col_node) {
			DLNode *node = col_node->down;
			node->up->down = node->down;
			node->down->up = node->up;
			delete node;
		}
		col_node->left->right = col_node->right;
		col_node->right->left = col_node->left;
		delete col_node;
	}
	delete head;
}

std::string DLX::toString() {
	std::string str { };
	DLNode *col_ptr = head->right;
	while (col_ptr != head) {
		DLNode *node = col_ptr->down;
		while (node != col_ptr) {
			str += "(" + std::to_string(node->row) + ", " + std::to_string(node->col) + ")\n";
			node = node->down;
		}
		col_ptr = col_ptr->right;
	}
	return str;
}
