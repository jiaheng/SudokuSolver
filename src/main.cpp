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
	std::string input { };
	std::string output { };

	// handle arguments
	std::vector<std::string> args(argv, argv+argc);
	input = args[1];
	for (size_t i = 2; i < args.size(); ++i) {
		if (args[i] == "-v") verbose = true;
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
	verbose = verbose || !write;	// verbose is on by default if no output file

	// reading sudoku from file
	std::ifstream infile(input);
	if (!infile.good()) {
		std::cout << "File does not exists! Exiting program" << std::endl;
		return 0;
	}
	std::string line { };
	std::vector<Sudoku> puzzles { };
	while (std::getline(infile, line)) {
		// read file line by line
		std::istringstream iss(line);
		puzzles.push_back(Sudoku(line));
	}
	infile.close();

	int index {0};
	unsigned int time {0};
	std::ofstream ofile { };
	// create output file if -o
	if (write) {
		ofile.open(output, std::ofstream::out);
		if (!ofile.is_open()) {
			std::cout << "Unable to create file '" << output << "'" << std::endl;
			write = false;
			verbose = true;
		}
	}
	// start solving puzzle
	for (auto &sudoku: puzzles) {
		std::cout << "Solving " << sudoku.getSize() << "x" << sudoku.getSize() << " puzzle #" << ++index << "...     " << std::flush;
		if (verbose)
			std::cout << std::endl << sudoku.toString() << std::endl;
		SudokuSolver solver(sudoku);
		clock_t start = clock();
		SudokuSolver::SSResult result = solver.search();
		clock_t end = clock();
		if (result.number_of_solution > 0) {
			std::cout << "Done!!!" << std::endl;
			Sudoku answer = result.solutions.front();
			if (verbose)
				std::cout << "Solution: for puzzle #" << index << std::endl << answer.toString() << std::endl;
		}
		else
			std::cout << "No solution found!" << std::endl;

		time += static_cast<unsigned int>(end - start);
		if (write) {
			std::string content = (result.number_of_solution > 0? result.solutions.front().toSimpleString() : "no solution.");
			ofile << content << "\r\n";
		}
	}
	if (ofile.is_open()) ofile.close();
	std::cout << "it took " << time << "ticks, or "
				<< ((float)time)/CLOCKS_PER_SEC
				<< "seconds to solve all " << index << " sudoku." << std::endl;
	return 0;
}
