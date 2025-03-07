################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_cortex.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dma.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dma_ex.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_exti.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_gpio.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pwr.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pwr_ex.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rcc.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rcc_ex.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rif.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_uart.c \
C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_uart_ex.c 

OBJS += \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_cortex.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma_ex.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_exti.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_gpio.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr_ex.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc_ex.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rif.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart.o \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart_ex.o 

C_DEPS += \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_cortex.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma_ex.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_exti.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_gpio.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr_ex.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc_ex.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rif.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart.d \
./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_cortex.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_cortex.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dma.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma_ex.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dma_ex.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_exti.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_exti.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_gpio.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_gpio.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pwr.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr_ex.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pwr_ex.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rcc.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc_ex.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rcc_ex.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rif.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rif.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_uart.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart_ex.o: C:/N6/HelloWorld/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_uart_ex.c Drivers/STM32N6xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I../STDIO -I../ExpressLink/App -I../ExpressLink -I../../Middlewares/ST/ExpressLink/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32N6xx_HAL_Driver

clean-Drivers-2f-STM32N6xx_HAL_Driver:
	-$(RM) ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_cortex.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_cortex.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_cortex.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_cortex.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma_ex.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma_ex.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma_ex.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_dma_ex.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_exti.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_exti.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_exti.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_exti.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_gpio.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_gpio.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_gpio.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_gpio.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr_ex.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr_ex.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr_ex.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_pwr_ex.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc_ex.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc_ex.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc_ex.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rcc_ex.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rif.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rif.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rif.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_rif.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart.su ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart_ex.cyclo ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart_ex.d ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart_ex.o ./Drivers/STM32N6xx_HAL_Driver/stm32n6xx_hal_uart_ex.su

.PHONY: clean-Drivers-2f-STM32N6xx_HAL_Driver

