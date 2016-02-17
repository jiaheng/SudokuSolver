################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Sudoku.cpp \
../src/SudokuSolver.cpp \
../src/SudokuSolver_test.cpp \
../src/Sudoku_test.cpp \
../src/Test.cpp 

OBJS += \
./src/Sudoku.o \
./src/SudokuSolver.o \
./src/SudokuSolver_test.o \
./src/Sudoku_test.o \
./src/Test.o 

CPP_DEPS += \
./src/Sudoku.d \
./src/SudokuSolver.d \
./src/SudokuSolver_test.d \
./src/Sudoku_test.d \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/jiaheng/git/SudokuSolver/cute" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


