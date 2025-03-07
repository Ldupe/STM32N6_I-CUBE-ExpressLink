################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/N6/HelloWorld/Middlewares/ST/STDIO/stdout_usart.c 

OBJS += \
./Middlewares/STDIO/Compiler/I\ O/STDOUT/USART/stdout_usart.o 

C_DEPS += \
./Middlewares/STDIO/Compiler/I\ O/STDOUT/USART/stdout_usart.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STDIO/Compiler/I\ O/STDOUT/USART/stdout_usart.o: C:/N6/HelloWorld/Middlewares/ST/STDIO/stdout_usart.c Middlewares/STDIO/Compiler/I\ O/STDOUT/USART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/STM32_ExtMem_Manager -I../../Middlewares/ST/STM32_ExtMem_Manager/boot -I../../Middlewares/ST/STM32_ExtMem_Manager/sal -I../../Middlewares/ST/STM32_ExtMem_Manager/nor_sfdp -I../../Middlewares/ST/STM32_ExtMem_Manager/psram -I../../Middlewares/ST/STM32_ExtMem_Manager/sdcard -I../../Middlewares/ST/STM32_ExtMem_Manager/user -I../STDIO -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"Middlewares/STDIO/Compiler/I O/STDOUT/USART/stdout_usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-STDIO-2f-Compiler-2f-I-20-O-2f-STDOUT-2f-USART

clean-Middlewares-2f-STDIO-2f-Compiler-2f-I-20-O-2f-STDOUT-2f-USART:
	-$(RM) ./Middlewares/STDIO/Compiler/I\ O/STDOUT/USART/stdout_usart.cyclo ./Middlewares/STDIO/Compiler/I\ O/STDOUT/USART/stdout_usart.d ./Middlewares/STDIO/Compiler/I\ O/STDOUT/USART/stdout_usart.o ./Middlewares/STDIO/Compiler/I\ O/STDOUT/USART/stdout_usart.su

.PHONY: clean-Middlewares-2f-STDIO-2f-Compiler-2f-I-20-O-2f-STDOUT-2f-USART

