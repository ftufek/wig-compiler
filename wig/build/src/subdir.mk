################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/empty_visitor.cc \
../src/lex.yy.cc \
../src/main.cc \
../src/pretty_printer.cc \
../src/weeder.cc \
../src/y.tab.cc 

OBJS += \
./src/empty_visitor.o \
./src/lex.yy.o \
./src/main.o \
./src/pretty_printer.o \
./src/weeder.o \
./src/y.tab.o 

CC_DEPS += \
./src/empty_visitor.d \
./src/lex.yy.d \
./src/main.d \
./src/pretty_printer.d \
./src/weeder.d \
./src/y.tab.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -std=gnu++11 -lboost_program_options -lfl -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


