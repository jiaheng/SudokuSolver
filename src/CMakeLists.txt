include_directories(${PROJECT_SRC_DIR}/src)

# Add all src files  
set (SOURCE_FILES DLNode.cpp DLX.cpp main.cpp Sudoku.cpp SudokuSolver.cpp)

add_executable(SudokuSolver ${SOURCE_FILES})
