#ifndef _HDR_SORTING_H_
#define _HDR_SORTING_H_

#include <vector>
using namespace std;

typedef void (*pFn)(vector<int>&);

//== Sorting
void insertion_sort(vector<int> &arr);
void merge_sort(vector<int> &arr);
void selection_sort(vector<int> &arr);
void bubble_sort(vector<int> &arr);
void heap_sort(vector<int> &arr);
void quick_sort(vector<int> &arr);

//== Testing
void create_proto_arrays();
void test_sorting(pFn f);

#endif
