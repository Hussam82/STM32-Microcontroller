################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADC_program.c \
../src/AFIO_program.c \
../src/BUTTON_program.c \
../src/DMA_program.c \
../src/EXTI_program.c \
../src/GPIO_program.c \
../src/LED_program.c \
../src/NVIC_program.c \
../src/PWM_program.c \
../src/RCC_program.c \
../src/SEVENSEG_program.c \
../src/STK_program.c \
../src/TIM_program.c \
../src/USART_program.c \
../src/main.c 

OBJS += \
./src/ADC_program.o \
./src/AFIO_program.o \
./src/BUTTON_program.o \
./src/DMA_program.o \
./src/EXTI_program.o \
./src/GPIO_program.o \
./src/LED_program.o \
./src/NVIC_program.o \
./src/PWM_program.o \
./src/RCC_program.o \
./src/SEVENSEG_program.o \
./src/STK_program.o \
./src/TIM_program.o \
./src/USART_program.o \
./src/main.o 

C_DEPS += \
./src/ADC_program.d \
./src/AFIO_program.d \
./src/BUTTON_program.d \
./src/DMA_program.d \
./src/EXTI_program.d \
./src/GPIO_program.d \
./src/LED_program.d \
./src/NVIC_program.d \
./src/PWM_program.d \
./src/RCC_program.d \
./src/SEVENSEG_program.d \
./src/STK_program.d \
./src/TIM_program.d \
./src/USART_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


