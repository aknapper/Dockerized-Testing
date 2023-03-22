#This makefile makes all the main book code with CppUTest test harness

#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = Dockerized-Testing-Template

#--- Inputs ----#
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .

SRC_DIRS = \
	src/swap\
	src/GpioDriver\

TEST_SRC_DIRS = \
	.\
	tests\
	tests/swap\
	tests/GpioDriver\

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include\
  src/swap\
  src/GpioDriver\

MOCKS_SRC_DIRS = \
	# mocks\

# put test build artifacts in build directory
BUILD_DIR = build/
CPPUTEST_LIB_DIR = $(BUILD_DIR)
CPPUTEST_OBJS_DIR = $(BUILD_DIR)

include CppUTestCompileFlags.mk
  
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
