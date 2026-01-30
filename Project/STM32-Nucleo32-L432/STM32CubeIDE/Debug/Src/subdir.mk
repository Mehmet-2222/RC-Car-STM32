################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/mado2/Downloads/Simple/Src/lib.cpp \
C:/Users/mado2/Downloads/Simple/Src/main.cpp 

S_SRCS += \
../startup.s 

S_DEPS += \
./Src/startup.d 

OBJS += \
./Src/lib.o \
./Src/main.o \
./Src/startup.o 

CPP_DEPS += \
./Src/lib.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/lib.o: C:/Users/mado2/Downloads/Simple/Src/lib.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DSTM32L432KCUx -DCOMPILER_GCC -DMCU_STM32L432xC -DOSCSRC=HSI -DOSCFREQ=4000 -DSTM32L432xx -c -I"C:/Users/mado2/Downloads/EmbSysLib-01.05.06/EmbSysLib-01.05.06/Src" -I"C:/Users/mado2/Downloads/EmbSysLib-01.05.06/EmbSysLib-01.05.06/Src/Hardware/MCU/STM32L4xx" -I"C:/Users/mado2/Downloads/EmbSysLib-01.05.06/EmbSysLib-01.05.06/Src/Hardware/MCU/STM32L4xx/Sys/GCC" -I../../../../Src/Board/STM32-Nucleo32-L432 -I../../../../Src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/main.o: C:/Users/mado2/Downloads/Simple/Src/main.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DSTM32L432KCUx -DCOMPILER_GCC -DMCU_STM32L432xC -DOSCSRC=HSI -DOSCFREQ=4000 -DSTM32L432xx -c -I"C:/Users/mado2/Downloads/EmbSysLib-01.05.06/EmbSysLib-01.05.06/Src" -I"C:/Users/mado2/Downloads/EmbSysLib-01.05.06/EmbSysLib-01.05.06/Src/Hardware/MCU/STM32L4xx" -I"C:/Users/mado2/Downloads/EmbSysLib-01.05.06/EmbSysLib-01.05.06/Src/Hardware/MCU/STM32L4xx/Sys/GCC" -I../../../../Src/Board/STM32-Nucleo32-L432 -I../../../../Src -O0 -ffunction-sections -fdata-sections -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/startup.o: C:/Users/mado2/Downloads/Simple/Project/STM32-Nucleo32-L432/STM32CubeIDE/startup.s Src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -DPROJECT_CPP -c -I"C:/Users/mado2/Downloads/EmbSysLib-01.05.06/EmbSysLib-01.05.06/Src/Hardware/MCU/STM32L4xx/Sys/GCC" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/lib.cyclo ./Src/lib.d ./Src/lib.o ./Src/lib.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/startup.d ./Src/startup.o

.PHONY: clean-Src

