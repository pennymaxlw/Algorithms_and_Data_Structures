SRC := $(wildcard *.cpp)
HDR := $(wildcard *.h)
OBJS_PATH := .obj/
OBJS := $(patsubst %.cpp,$(OBJS_PATH)%.o,$(SRC))
TARGET := $(patsubst %.cpp,%,$(SRC))
CC := g++
CFLAGS := -Wall -O
INCLUDES := -I../basic/
LIBS := -L../basic -lmybasic

all : $(TARGET)

MKDIR:
	if [ ! -d $(OBJS_PATH) ];then\
		mkdir .obj;\
	fi\

% : %.cpp
	$(CC) $(CFLAGS) $< $(INCLUDES) $(LIBS) -o $@ 

clean:
	rm -rf $(TARGET)

