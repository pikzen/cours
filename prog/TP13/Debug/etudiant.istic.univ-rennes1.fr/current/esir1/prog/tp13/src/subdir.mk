################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../etudiant.istic.univ-rennes1.fr/current/esir1/prog/tp13/src/main.cpp 

OBJS += \
./etudiant.istic.univ-rennes1.fr/current/esir1/prog/tp13/src/main.o 

CPP_DEPS += \
./etudiant.istic.univ-rennes1.fr/current/esir1/prog/tp13/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
etudiant.istic.univ-rennes1.fr/current/esir1/prog/tp13/src/%.o: ../etudiant.istic.univ-rennes1.fr/current/esir1/prog/tp13/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


