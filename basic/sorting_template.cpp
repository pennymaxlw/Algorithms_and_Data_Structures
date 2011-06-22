#include "sorting_template.h"
#include <iostream>
#include <list>
using namespace std;

void test_sorting_template() {
	int arr[] = {5,4,6,9,8,10,30,16,4,16,8};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(int));
	//list<int> v(arr, arr + sizeof(arr)/sizeof(int));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	std::cout << std::endl;
	
	//merge_sort(v.begin(), v.end());
	//insertion_sort(v.begin(), v.end());
	//selection_sort(v.begin(), v.end());
	//bubble_sort(v.begin(), v.end());
	//quick_sort(v.begin(), v.end());
	counting_sort(v.begin(), v.end());
	
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	std::cout << std::endl;
}

