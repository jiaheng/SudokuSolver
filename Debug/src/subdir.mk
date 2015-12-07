################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SimpleSudokuSolver.cpp \
../src/Sudoku.cpp \
../src/Test.cpp 

OBJS += \
./src/SimpleSudokuSolver.o \
./src/Sudoku.o \
./src/Test.o 

CPP_DEPS += \
./src/SimpleSudokuSolver.d \
./src/Sudoku.d \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/jiaheng/workspace/SudokuSolver/cute" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


