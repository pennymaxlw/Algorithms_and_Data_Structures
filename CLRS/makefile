CC := g++
CFLAGS := -Wall -O
BASIC_PATH := ../basic
BASIC_OBJS := $(BASIC_PATH)/.obj
INCLUDES := -I$(BASIC_PATH)
BUILD = $(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

all : exe2.3.7

exe2.3.7 : exe2.3.7.cpp $(BASIC_OBJS)/helper.o  $(BASIC_OBJS)/sorting.o
	$(BUILD)

clean:
