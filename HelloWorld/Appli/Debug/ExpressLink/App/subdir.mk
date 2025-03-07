################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ExpressLink/App/app_I-CUBE-ExpressLink.c 

OBJS += \
./ExpressLink/App/app_I-CUBE-ExpressLink.o 

C_DEPS += \
./ExpressLink/App/app_I-CUBE-ExpressLink.d 


# Each subdirectory must supply rules for building sources it contributes
ExpressLink/App/%.o ExpressLink/App/%.su ExpressLink/App/%.cyclo: ../ExpressLink/App/%.c ExpressLink/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ExpressLink-2f-App

clean-ExpressLink-2f-App:
	-$(RM) ./ExpressLink/App/app_I-CUBE-ExpressLink.cyclo ./ExpressLink/App/app_I-CUBE-ExpressLink.d ./ExpressLink/App/app_I-CUBE-ExpressLink.o ./ExpressLink/App/app_I-CUBE-ExpressLink.su

.PHONY: clean-ExpressLink-2f-App

