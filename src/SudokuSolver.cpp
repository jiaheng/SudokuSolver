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
 * SimpleSudokuSolver.cpp
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "SudokuSolver.hpp"
#include "Sudoku.hpp"
#include "DLX.hpp"

SudokuSolver::SudokuSolver(Sudoku puzzle) {
	m_puzzle = Sudoku(puzzle);
	m_size = m_puzzle.getSize();
}

SudokuSolver::SudokuSolver(int **const arr, int m_size) {
	m_puzzle = Sudoku(arr, m_size);
	m_size = m_puzzle.getSize();
}

Sudoku SudokuSolver::getSolution() {
	solve();
	return m_puzzle;
	// TODO: remove. no longer use multi thread **ALSO REMOVE -pthread PARAMETER!!!
	/*
	if (multithread) {
		std::thread t1(&SudokuSolver::newThreadSolve, this, 0, 0, m_puzzle);
		t1.join();
	} else {
		solve(0, 0, m_puzzle);
	}
	return m_puzzle;
	*/
}

void SudokuSolver::solve() {
	std::vector<std::vector <int>> matrix = toExactCover();
	DLX dlx { matrix };
	//TODO: remove println
	/*/
	std::cout << "for puzzle: " << std::endl << m_puzzle.toString() << std::endl;
	std::cout << "matrix size row: " << matrix.size() << ". col: " << matrix[0].size() << std::endl << "martrix: " << std::endl;
	std::cout << "54 : " << getNumFromEC(matrix[54]) << std::endl;
	for (auto c : matrix[54])
			std::cout << c << " ";
	std::cout << std::endl;
	std::cout << "63 : " << getNumFromEC(matrix[63]) << std::endl;
	for (auto c : matrix[63])
		std::cout << c << " ";
	std::cout << std::endl;
	//
	for (auto row : matrix) {
		for (auto num : row) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
	/*/
	assert(dlx.solve());
	std::vector<int> solution = dlx.getSolution();
	fillSudoku(matrix, solution);
}

std::vector<std::vector<int> > SudokuSolver::toExactCover() {
	std::vector<std::vector <int>> matrix { };
	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			int num = m_puzzle.getCell(i, j);
			if (num == 0) {
				for (int p_num = 1; p_num <= m_size; ++p_num) {
					std::vector<int> row = toExactCoverRow(i, j, p_num);
					matrix.push_back(row);
					//TODO: remove test code below
					/*/
					if (matrix.size() == 55 || matrix.size() == 64) {
						std::cout << "(" << p_num << ", " << i << ", " << j << ")" << std::endl;
						for (auto c : row)
							std::cout << c << " ";
						std::cout << std::endl;
					}
					/*/
				}
			} else {
				std::vector<int> row = toExactCoverRow(i, j, num);
				//TODO: use push_bash instead this tedious
				auto it = matrix.begin();
				matrix.insert(it, row);
				//matrix.push_back(row);
				//TODO: remove test code below
				/*/
				if (matrix.size() == 55 || matrix.size() == 64) {
					std::cout << "(" << num << ", " << i << ", " << j << ")" << std::endl;
					for (auto c : row)
						std::cout << c << " ";
					std::cout << std::endl;
				}
				/*/
			}
		}
	}
	return matrix;
}

std::vector<int> SudokuSolver::toExactCoverRow(int row, int col, int num) {
	std::vector<int> ec_row { };
	int sqrt_size { static_cast<int>(std::sqrt(m_size)) };
	int sqr_size { static_cast<int>(std::pow(m_size, 2)) };
	ec_row.resize(static_cast<int>(sqr_size*4));
	int pos { row * m_size + col };
	int cond_row { row * m_size + (num - 1) + sqr_size };
	int cond_col { col * m_size + (num - 1) + 2 * sqr_size};
	int cond_region { (row / sqrt_size * sqrt_size + col / sqrt_size) * m_size
			+ (num - 1) + 3 * sqr_size };
	ec_row[pos] = 1;
	ec_row[cond_row] = 1;
	ec_row[cond_col] = 1;
	ec_row[cond_region] = 1;
	return ec_row;
}

void SudokuSolver::fillSudoku(std::vector<std::vector<int> > matrix,
		std::vector<int> solution) {
	for (auto row : solution)
		rowToSudoku(matrix[row]);
}

void SudokuSolver::rowToSudoku(std::vector<int> sol) {
	int sqr_size = pow(m_size,2);
	// find row
	auto it = std::find(sol.begin(), sol.begin() + (sqr_size-1), 1);
	assert(it != sol.end());
	int pos = std::distance(sol.begin(), it);
	int col { pos % m_size };
	int row { (pos - col) / m_size };
	it = std::find(sol.begin() + sqr_size, sol.begin() + (2*sqr_size-1), 1);
	assert(it != sol.end());
	int cond_row = std::distance(sol.begin(), it);
	int num { cond_row % m_size + 1 };
	m_puzzle.setCell(row, col, num);
}

std::string SudokuSolver::getNumFromEC(std::vector<int> sol) {
	int sqr_size = pow(m_size,2);
	// find row
	auto it = std::find(sol.begin(), sol.begin() + (sqr_size-1), 1);
	assert(it != sol.end());
	int pos = std::distance(sol.begin(), it);
	int col { pos % m_size };
	int row { (pos - col) / m_size };
	it = std::find(sol.begin() + sqr_size, sol.begin() + (2*sqr_size-1), 1);
	assert(it != sol.end());
	int cond_row = std::distance(sol.begin(), it);
	int num { cond_row % m_size + 1 };
	return "(" + std::to_string(num) + ", " + std::to_string(row) + ", " + std::to_string(col) + ")";
}
