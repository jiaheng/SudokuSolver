# Add all src files
file(GLOB SOURCE_FILES
  "*.c"
  "*.cpp")

add_executable(SudokuSolverApp
  ${SOURCE_FILES})
target_link_libraries(SudokuSolverApp
  Dlx
  SudokuSolver)
