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

#include "gtest/gtest.h"
#include <algorithm>
#include <iostream>
#include <vector>

#include "DLNode.hpp"
#include "DLX.hpp"

namespace
{
std::vector<std::vector<int>> problemMatrix()
{
    /*
     * 0 0 1 0 1 1 0
     * 1 0 0 1 0 0 1
     * 0 1 1 0 0 1 0
     * 1 0 0 1 0 0 0
     * 0 1 0 0 0 0 1
     * 0 0 0 1 1 0 1
     */
    std::vector<std::vector<int>> matrix{};
    std::vector<int> row{};
    row = {0, 0, 1, 0, 1, 1, 0};
    matrix.push_back(row);
    row = {1, 0, 0, 1, 0, 0, 1};
    matrix.push_back(row);
    row = {0, 1, 1, 0, 0, 1, 0};
    matrix.push_back(row);
    row = {1, 0, 0, 1, 0, 0, 0};
    matrix.push_back(row);
    row = {0, 1, 0, 0, 0, 0, 1};
    matrix.push_back(row);
    row = {0, 0, 0, 1, 1, 0, 1};
    matrix.push_back(row);
    return matrix;
}

std::vector<std::vector<int>> multiSolutionMatrix()
{
    /*
     * 0 0 0 0 0 1	[1]	[2]
     * 0 0 0 0 0 1 	[duplicate]
     * 0 0 0 1 0 0	[1]
     * 0 1 0 0 0 0	[1]
     * 1 0 0 0 0 0  [1]	[2]
     * 0 1 1 0 0 0		[2]
     * 0 0 1 0 0 0	[1]
     * 0 0 0 0 1 0	[1]
     * 0 0 0 1 1 0		[2]
     * 1 0 0 0 0 0	[duplicate]
     * 1 0 0 0 0 0	[duplicate]
     * 0 1 0 0 0 0	[duplicate]
     */
    std::vector<std::vector<int>> matrix{};
    matrix.push_back({0, 0, 0, 0, 0, 1});
    matrix.push_back({0, 0, 0, 0, 0, 1});
    matrix.push_back({0, 0, 0, 1, 0, 0});
    matrix.push_back({0, 1, 0, 0, 0, 0});
    matrix.push_back({1, 0, 0, 0, 0, 0});
    matrix.push_back({0, 1, 1, 0, 0, 0});
    matrix.push_back({0, 0, 1, 0, 0, 0});
    matrix.push_back({0, 0, 0, 0, 1, 0});
    matrix.push_back({0, 0, 0, 1, 1, 0});
    matrix.push_back({1, 0, 0, 0, 0, 0});
    matrix.push_back({1, 0, 0, 0, 0, 0});
    matrix.push_back({0, 1, 0, 0, 0, 0});
    return matrix;
}

TEST(DlxTest, ConstructorTest)
{
    std::vector<std::vector<int>> matrix{};
    std::vector<int> row{0, 1, 0};
    matrix.push_back(row);
    row = {1, 1, 1};
    matrix.push_back(row);
    row = {1, 0, 0};
    matrix.push_back(row);
    row = {0, 0, 1};
    matrix.push_back(row);
    DLX dlx{matrix};
}

TEST(DlxTest, SingleSolutionTest)
{
    auto matrix = problemMatrix();
    DLX dlx{matrix};
    dlx.solve();
    auto result = dlx.getSolution();
    EXPECT_EQ(3, result.size()) << "Solution size not Equal";
    EXPECT_NE(std::find(result.begin(), result.end(), 0), result.end())
        << "Solution does not contain 0";
    EXPECT_NE(std::find(result.begin(), result.end(), 3), result.end())
        << "Solution does not contain 3";
    EXPECT_NE(std::find(result.begin(), result.end(), 4), result.end())
        << "Solution does not contain 4";
}

TEST(DlxTest, MultiSolutionTest)
{
    auto matrix = multiSolutionMatrix();
    DLX dlx{matrix};
    dlx.solve();
    auto result = dlx.getSolution();
    ASSERT_GT(result.size(), 0) << "No solution found!!!";
    std::vector<int> matrix_check{};
    matrix_check.resize(matrix[0].size());
    for (auto index : result)
    {
        for (unsigned i = 0; i < matrix[index].size(); ++i)
        {
            if (matrix[index][i] == 1)
            {
                EXPECT_NE(matrix[index][i], matrix_check[i])
                    << "Conflict at " + std::to_string(index) + " found!!!";
                matrix_check[i] = matrix[index][i];
            }
        }
    }
}

std::vector<std::vector<int>> noSolutionMatrix()
{
    /*
     * 0 0 0 0 0 0 1	[1]	[2]
     * 0 0 0 0 0 0 1 	[duplicate]
     * 0 0 0 0 1 0 0	[1]
     * 0 0 1 0 0 0 0	[1]
     * 0 1 0 0 0 0 0  [1]	[2]
     * 0 0 1 1 0 0 0		[2]
     * 0 0 0 1 0 0 0	[1]
     * 0 0 0 0 0 1 0	[1]
     * 0 0 0 0 1 1 0		[2]
     * 0 1 0 0 0 0 0	[duplicate]
     * 0 1 0 0 0 0 0	[duplicate]
     * 0 0 1 0 0 0 0	[duplicate]
     */
    std::vector<std::vector<int>> matrix{};
    matrix.push_back({0, 0, 0, 0, 0, 0, 1});
    matrix.push_back({0, 0, 0, 0, 0, 0, 1});
    matrix.push_back({0, 0, 0, 0, 1, 0, 0});
    matrix.push_back({0, 0, 1, 0, 0, 0, 0});
    matrix.push_back({0, 1, 0, 0, 0, 0, 0});
    matrix.push_back({0, 0, 1, 1, 0, 0, 0});
    matrix.push_back({0, 0, 0, 1, 0, 0, 0});
    matrix.push_back({0, 0, 0, 0, 0, 1, 0});
    matrix.push_back({0, 0, 0, 0, 1, 1, 0});
    matrix.push_back({0, 1, 0, 0, 0, 0, 0});
    matrix.push_back({0, 1, 0, 0, 0, 0, 0});
    matrix.push_back({0, 0, 1, 0, 0, 0, 0});
    return matrix;
}

TEST(DlxTest, NoSolutionTest)
{
    auto matrix = noSolutionMatrix();
    DLX dlx{matrix};
    EXPECT_FALSE(dlx.solve());
    auto result = dlx.getSolution();
    EXPECT_EQ(0, result.size()) << "Expected no solution (size ==0)!!!";
}
} // namespace
