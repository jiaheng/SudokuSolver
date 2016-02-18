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

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "Sudoku.hpp"
#include "SudokuSolver.hpp"

int main(int argc, char* argv[]) {
	bool verbose { false };
	bool write { false };
	bool multi_thread { true };
	std::string input { };
	std::string output { };

	// handle arguments
	std::vector<std::string> args(argv, argv+argc);
	input = args[1];
	for (size_t i = 2; i < args.size(); ++i) {
		if (args[i] == "-v") verbose = true;
		if (args[i] == "-no_mt") multi_thread = false;
		else if (args[i] == "-o") {
			write = true;
			// if there is no other argument after -o
			if (i+1 == args.size()) {
				std::cout << "Please specify the output file name." << std::endl;
				return 0;
			}
			output = args[++i];
		}
	}
	verbose = verbose || !write;

	std::ifstream infile(input);
	if (!infile.good()) {
		std::cout << "File does not exists! Exiting program" << std::endl;
		return 0;
	}

	// reading 9x9 sudoku
	std::string line { };
	std::vector<Sudoku> puzzles { };
	while (std::getline(infile, line)) {
		// read file line by line
		std::istringstream iss(line);
		puzzles.push_back(Sudoku(line));
	}
	int index {0};
	unsigned int time {0};
	for (auto &sudoku: puzzles) {
		std::cout << "Solving 9x9 puzzle #" << ++index << "..." << std::endl;
		if (verbose)
			std::cout << sudoku.toString() << std::endl;
		SudokuSolver solver(sudoku, multi_thread);
		clock_t start = clock();
		Sudoku solution = solver.getSolution();
		std::cout << "Done!!!" << std::endl;
		if (verbose)
			std::cout << "Solution: for puzzle #" << index << std::endl << solution.toString() << std::endl;
		clock_t end = clock();
		time += static_cast<unsigned int>(end - start);
		if (write) {
			std::ofstream ofile (output);
			if (ofile.is_open()) {
				ofile << solution.toSimpleString();
				ofile.close();
			}
			else {
				std::cout << "Unable to open file";
				write = false;
			}
		}
	}
	std::cout << "it took " << time << "ticks, or "
				<< ((float)time)/CLOCKS_PER_SEC
				<< "seconds to solve all " << index << " 9x9 sudoku." << std::endl;
	return 0;
}
