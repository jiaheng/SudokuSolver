add_executable(SudokuTests
  Sudoku_test.cpp)
add_executable(SudokuSolverTests
  SudokuSolver_test.cpp)

# Standard linking to gtest stuff.
target_link_libraries(SudokuTests gtest gtest_main)
target_link_libraries(SudokuSolverTests gtest gtest_main)

# Extra linking for the project.
target_link_libraries(SudokuTests SudokuSolver)
target_link_libraries(SudokuSolverTests SudokuSolver)

# copy test resources
configure_files(
  ${PROJECT_SOURCE_DIR}/sample
  ${CMAKE_CURRENT_BINARY_DIR}/sample)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(SudokuTests SudokuTests)
add_test(SudokuSolverTests SudokuSolverTests)
