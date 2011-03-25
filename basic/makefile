CC := g++
CFLAGS := -Wall -O
COMPILE_OBJ = $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : cmd test_sorting binary_searching

cmd:
	if [ ! -d .obj ];then \
		mkdir .obj; \
	fi \

.obj/test_sorting.o : test_sorting.cpp helper.h sorting.h
	$(COMPILE_OBJ)

.obj/binary_searching.o : binary_searching.cpp helper.h
	$(COMPILE_OBJ)

.obj/sorting.o : sorting.cpp helper.h sorting.h
	$(COMPILE_OBJ)

.obj/helper.o : helper.cpp helper.h
	$(COMPILE_OBJ)

test_sorting : .obj/sorting.o .obj/helper.o .obj/test_sorting.o
	$(CC) -o test_sorting $^

binary_searching : .obj/helper.o .obj/binary_searching.o
	$(CC) -o binary_searching $^

clean:
	rm -rf .obj test_sorting binary_searching
