SRC := $(wildcard *.cpp)
HDR := $(wildcard *.h)
OBJS_PATH := .obj/
OBJS := $(patsubst %.cpp,$(OBJS_PATH)%.o,$(SRC))
TARGET := test
CC := g++
CFLAGS := -Wall -O
INCLUDES :=
LIBS :=

all : MKDIR $(TARGET)

MKDIR:
	if [ ! -d $(OBJS_PATH) ];then\
		mkdir .obj;\
	fi\

$(OBJS_PATH)%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(LIBS) $(OBJS) 

clean:
	rm -rf $(OBJS_PATH) $(TARGET)

