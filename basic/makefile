SRC := $(wildcard *.cpp)
HDR := $(wildcard *.h)
OBJS_PATH := .obj/
OBJS := $(patsubst %.cpp,$(OBJS_PATH)%.o,$(SRC))
OBJS_LIB = $(filter-out .obj/test.o,$(OBJS))
TARGET := test.exe
STATIC_LIB := libmybasic.a
CC := g++
CFLAGS := -Wall -O
INCLUDES :=
LIBS :=

all : MKDIR $(TARGET) lib

lib : $(STATIC_LIB)

$(STATIC_LIB): $(OBJS)
	ar rcs $@ $(OBJS_LIB)

MKDIR:
	if [ ! -d $(OBJS_PATH) ];then\
		mkdir .obj;\
	fi\

$(OBJS_PATH)%.o : %.cpp %.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(LIBS) $(OBJS) 

clean:
	rm -rf $(OBJS_PATH) $(TARGET) $(STATIC_LIB)

