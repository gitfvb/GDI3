################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/threads2.o 

C_SRCS += \
../src/gdi3_uebungen.c \
../src/main.c \
../src/sandbox.c \
../src/threads.c \
../src/threads2.c \
../src/uebung11.c \
../src/uebung9.c 

OBJS += \
./src/gdi3_uebungen.o \
./src/main.o \
./src/sandbox.o \
./src/threads.o \
./src/threads2.o \
./src/uebung11.o \
./src/uebung9.o 

C_DEPS += \
./src/gdi3_uebungen.d \
./src/main.d \
./src/sandbox.d \
./src/threads.d \
./src/threads2.d \
./src/uebung11.d \
./src/uebung9.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -arch i386 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/threads.o: ../src/threads.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -arch i386 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/threads.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/threads2.o: ../src/threads2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -arch i386 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/threads2.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


