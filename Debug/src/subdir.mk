################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/tp\ 1.c 

OBJS += \
./src/tp\ 1.o 

C_DEPS += \
./src/tp\ 1.d 


# Each subdirectory must supply rules for building sources it contributes
src/tp\ 1.o: ../src/tp\ 1.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/tp 1.d" -MT"src/tp\ 1.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


