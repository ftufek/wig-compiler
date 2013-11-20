################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/symbol_table/table.cc 

OBJS += \
./src/symbol_table/table.o 

CC_DEPS += \
./src/symbol_table/table.d 


# Each subdirectory must supply rules for building sources it contributes
src/symbol_table/%.o: ../src/symbol_table/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -std=gnu++11 -lboost_program_options -lfl -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


