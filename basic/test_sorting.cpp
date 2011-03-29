#include "sorting.h"
#include "helper.h"
#include <iostream>
using namespace std;

int main()
{
	pFn f = NULL;

	create_proto_arrays();

	cout << endl;
	cout << "\n=========== Insertion sort ==========" << endl;
	f = insertion_sort;
	test_sorting(f);

	cout << "\n=========== Selection sort ==========" << endl;
	f = selection_sort;
	test_sorting(f);

	cout << "\n=========== Merge sort ==========" << endl;
	f = merge_sort;
	test_sorting(f);

	cout << "\n=========== Bubble sort ==========" << endl;
	f = bubble_sort;
	test_sorting(f);

	cout << "\n=========== Heap sort ==========" << endl;
	f = heap_sort;
	test_sorting(f);

	cout << "\n=========== Quick sort ==========" << endl;
	f = quick_sort;
	test_sorting(f);
}
