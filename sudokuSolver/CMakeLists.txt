# Add all src files
file(GLOB LIB_SRC_FILES
  "src/*.c"
  "src/*.cpp")

add_library(SudokuSolver STATIC
  ${LIB_SRC_FILES})

target_link_libraries(SudokuSolver
  Dlx)

target_include_directories(SudokuSolver PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)
