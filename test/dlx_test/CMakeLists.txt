add_executable(DLXTests
  DLX_test.cpp)

# Standard linking to gtest stuff.
target_link_libraries(DLXTests gtest gtest_main)

# Extra linking for the project.
target_link_libraries(DLXTests Dlx)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(DLXTests DLXTests)
