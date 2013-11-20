################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/parser/lex.yy.cc \
../src/parser/y.tab.cc 

OBJS += \
./src/parser/lex.yy.o \
./src/parser/y.tab.o 

CC_DEPS += \
./src/parser/lex.yy.d \
./src/parser/y.tab.d 


# Each subdirectory must supply rules for building sources it contributes
src/parser/%.o: ../src/parser/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -std=gnu++11 -lboost_program_options -lfl -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


