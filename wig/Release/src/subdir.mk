################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/ast_visitor.cc \
../src/lex.yy.cc \
../src/main.cc \
../src/pretty_printer.cc \
../src/sym_tabler.cc \
../src/weeder.cc \
../src/y.tab.cc 

OBJS += \
./src/ast_visitor.o \
./src/lex.yy.o \
./src/main.o \
./src/pretty_printer.o \
./src/sym_tabler.o \
./src/weeder.o \
./src/y.tab.o 

CC_DEPS += \
./src/ast_visitor.d \
./src/lex.yy.d \
./src/main.d \
./src/pretty_printer.d \
./src/sym_tabler.d \
./src/weeder.d \
./src/y.tab.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=c++11 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


