################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/DR_c/HAL/AlternativePin.cpp \
../Src/DR_c/HAL/InputPin.cpp \
../Src/DR_c/HAL/OutputPin.cpp \
../Src/DR_c/HAL/PWM.cpp \
../Src/DR_c/HAL/Pin.cpp 

OBJS += \
./Src/DR_c/HAL/AlternativePin.o \
./Src/DR_c/HAL/InputPin.o \
./Src/DR_c/HAL/OutputPin.o \
./Src/DR_c/HAL/PWM.o \
./Src/DR_c/HAL/Pin.o 

CPP_DEPS += \
./Src/DR_c/HAL/AlternativePin.d \
./Src/DR_c/HAL/InputPin.d \
./Src/DR_c/HAL/OutputPin.d \
./Src/DR_c/HAL/PWM.d \
./Src/DR_c/HAL/Pin.d 


# Each subdirectory must supply rules for building sources it contributes
Src/DR_c/HAL/AlternativePin.o: ../Src/DR_c/HAL/AlternativePin.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/DR_c/HAL/AlternativePin.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/DR_c/HAL/InputPin.o: ../Src/DR_c/HAL/InputPin.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/DR_c/HAL/InputPin.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/DR_c/HAL/OutputPin.o: ../Src/DR_c/HAL/OutputPin.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/DR_c/HAL/OutputPin.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/DR_c/HAL/PWM.o: ../Src/DR_c/HAL/PWM.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/DR_c/HAL/PWM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/DR_c/HAL/Pin.o: ../Src/DR_c/HAL/Pin.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/DR_c/HAL/Pin.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

