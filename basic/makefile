CC := g++
CFLAGS := -Wall -O
COMPILE_OBJ = $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Default targets
all : cmd test_sorting binary_searching 

cmd:
	if [ ! -d .obj ];then \
		mkdir .obj; \
	fi \

# OBJs
.obj/test_sorting.o : test_sorting.cpp helper.h sorting.h
	$(COMPILE_OBJ)

.obj/binary_searching.o : binary_searching.cpp helper.h
	$(COMPILE_OBJ)

.obj/maximum_subarray.o : maximum_subarray.cpp helper.h
	$(COMPILE_OBJ)

.obj/sorting.o : sorting.cpp helper.h sorting.h data_structures.h
	$(COMPILE_OBJ)

.obj/data_structures.o : data_structures.cpp data_structures.h helper.h
	$(COMPILE_OBJ)

.obj/helper.o : helper.cpp helper.h
	$(COMPILE_OBJ)

# Targets
test_sorting : .obj/sorting.o .obj/helper.o .obj/test_sorting.o .obj/data_structures.o
	$(CC) -o test_sorting $^

binary_searching : .obj/helper.o .obj/binary_searching.o
	$(CC) -o binary_searching $^

maximum_subarray : .obj/helper.o .obj/maximum_subarray.o
	$(CC) -o binary_searching $^

clean:
	rm -rf .obj test_sorting binary_searching maximum_subarray
