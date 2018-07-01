/*
 * SudokuSolver.hpp
 *
 *  Created on: 6 Dec 2015
 *      Author: jiaheng
 */

#ifndef SRC_SUDOKUSOLVER_HPP_
#define SRC_SUDOKUSOLVER_HPP_

#include "Sudoku.hpp"

class SudokuSolver {
public:
  struct SSResult {
    // sudoku solver result
    unsigned number_of_solution = 0;
    std::vector<Sudoku> solutions;
  };

private:
  Sudoku m_puzzle;
  int m_size{};

public:
  SudokuSolver(Sudoku puzzle);
  SudokuSolver(int **const arr, int size);
  SSResult search();

private:
  std::vector<std::vector<int>> toExactCover();
  std::vector<int> toExactCoverRow(int row, int col, int num);
  void rowToSudoku(std::vector<int> row, Sudoku *sudoku);
  std::string getNumFromEC(std::vector<int> row);
  Sudoku toSudoku(std::vector<std::vector<int>> matrix,
                  std::vector<int> solution);
};

#endif /* SRC_SUDOKUSOLVER_HPP_ */
