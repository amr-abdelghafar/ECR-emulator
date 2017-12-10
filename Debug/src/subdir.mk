################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ECR\ Emulator.cpp 

OBJS += \
./src/ECR\ Emulator.o 

CPP_DEPS += \
./src/ECR\ Emulator.d 


# Each subdirectory must supply rules for building sources it contributes
src/ECR\ Emulator.o: ../src/ECR\ Emulator.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/ECR Emulator.d" -MT"src/ECR\ Emulator.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


