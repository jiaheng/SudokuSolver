# Add all src files
file(GLOB SOURCE_FILES
  "*.h"
  "*.c"
  "*.hpp"
  "*.cpp")

add_executable(SudokuSolverApp
  ${SOURCE_FILES})
target_link_libraries(SudokuSolverApp
  Dlx
  SudokuSolver)
