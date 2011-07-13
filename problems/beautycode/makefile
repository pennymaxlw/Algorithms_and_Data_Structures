SRC := $(wildcard *.cpp)
HDR := $(wildcard *.h)
OBJS_PATH := .obj/
OBJS := $(patsubst %.cpp,$(OBJS_PATH)%.o,$(SRC))
TARGET := $(patsubst %.cpp,%.exe,$(SRC))
CC := g++
CFLAGS := -Wall -O
#INCLUDES := -I../basic/
#LIBS := -L../basic -lmybasic

all : $(TARGET)

%.exe : %.cpp
	$(CC) $(CFLAGS) $< $(INCLUDES) $(LIBS) -o $@ 

clean:
	rm -rf $(TARGET)

