set(CMAKE_TEST_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

add_executable(runUnitTests
  SampleTest.cpp)

# Standard linking to gtest stuff.
target_link_libraries(runUnitTests gtest gtest_main)

# Extra linking for the project.
target_link_libraries(runUnitTests Dlx)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(UnitTests ${CMAKE_TEST_BIN_DIR}/runUnitTests)

add_subdirectory(dlx_test)
