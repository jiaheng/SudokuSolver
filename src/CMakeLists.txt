include_directories(${PROJECT_SRC_DIR}/src)

# Add all src files  
set (SOURCE_FILES main.cpp Sudoku.cpp SudokuSolver.cpp)
set (LIB_FILES DLNode.cpp DLX.cpp)

add_library(Dlx ${LIB_FILES})
add_executable(SudokuSolver ${SOURCE_FILES})
target_link_libraries(SudokuSolver Dlx) 