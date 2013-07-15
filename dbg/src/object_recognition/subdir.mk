# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += ../src/object_recognition/object_recognizer.cpp \

OBJS += ./src/object_recognition/object_recognizer.o \

CPP_DEPS += ./src/object_recognition/object_recognizer.d \


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	$(CXX) `pkg-config --cflags opencv` -std=c++11 \
		-c -fmessage-length=0 -MMD -MP \
		-MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

