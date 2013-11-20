################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/ast.cc \
../src/codegen.cc \
../src/error.cc \
../src/main.cc \
../src/pretty_printer.cc \
../src/sym_tabler.cc \
../src/typechecker.cc \
../src/weeder.cc 

OBJS += \
./src/ast.o \
./src/codegen.o \
./src/error.o \
./src/main.o \
./src/pretty_printer.o \
./src/sym_tabler.o \
./src/typechecker.o \
./src/weeder.o 

CC_DEPS += \
./src/ast.d \
./src/codegen.d \
./src/error.d \
./src/main.d \
./src/pretty_printer.d \
./src/sym_tabler.d \
./src/typechecker.d \
./src/weeder.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -std=gnu++11 -lboost_program_options -lfl -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


