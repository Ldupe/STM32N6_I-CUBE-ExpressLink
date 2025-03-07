################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/N6/HelloWorld/Middlewares/ST/ExpressLink/Src/ExpressLink.c 

OBJS += \
./Middlewares/ExpressLink/Driver/ExpressLink/ExpressLink.o 

C_DEPS += \
./Middlewares/ExpressLink/Driver/ExpressLink/ExpressLink.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ExpressLink/Driver/ExpressLink/ExpressLink.o: C:/N6/HelloWorld/Middlewares/ST/ExpressLink/Src/ExpressLink.c Middlewares/ExpressLink/Driver/ExpressLink/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ExpressLink-2f-Driver-2f-ExpressLink

clean-Middlewares-2f-ExpressLink-2f-Driver-2f-ExpressLink:
	-$(RM) ./Middlewares/ExpressLink/Driver/ExpressLink/ExpressLink.cyclo ./Middlewares/ExpressLink/Driver/ExpressLink/ExpressLink.d ./Middlewares/ExpressLink/Driver/ExpressLink/ExpressLink.o ./Middlewares/ExpressLink/Driver/ExpressLink/ExpressLink.su

.PHONY: clean-Middlewares-2f-ExpressLink-2f-Driver-2f-ExpressLink

