################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/ast/argument.cc \
../src/ast/ast.cc \
../src/ast/empty.cc \
../src/ast/exp.cc \
../src/ast/field.cc \
../src/ast/function.cc \
../src/ast/helpers.cc \
../src/ast/html.cc \
../src/ast/list.cc \
../src/ast/meta.cc \
../src/ast/schema.cc \
../src/ast/service.cc \
../src/ast/session.cc \
../src/ast/stm.cc \
../src/ast/string.cc \
../src/ast/type.cc \
../src/ast/variable.cc \
../src/ast/whatever.cc 

OBJS += \
./src/ast/argument.o \
./src/ast/ast.o \
./src/ast/empty.o \
./src/ast/exp.o \
./src/ast/field.o \
./src/ast/function.o \
./src/ast/helpers.o \
./src/ast/html.o \
./src/ast/list.o \
./src/ast/meta.o \
./src/ast/schema.o \
./src/ast/service.o \
./src/ast/session.o \
./src/ast/stm.o \
./src/ast/string.o \
./src/ast/type.o \
./src/ast/variable.o \
./src/ast/whatever.o 

CC_DEPS += \
./src/ast/argument.d \
./src/ast/ast.d \
./src/ast/empty.d \
./src/ast/exp.d \
./src/ast/field.d \
./src/ast/function.d \
./src/ast/helpers.d \
./src/ast/html.d \
./src/ast/list.d \
./src/ast/meta.d \
./src/ast/schema.d \
./src/ast/service.d \
./src/ast/session.d \
./src/ast/stm.d \
./src/ast/string.d \
./src/ast/type.d \
./src/ast/variable.d \
./src/ast/whatever.d 


# Each subdirectory must supply rules for building sources it contributes
src/ast/%.o: ../src/ast/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -std=gnu++11 -lboost_program_options -lfl -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


