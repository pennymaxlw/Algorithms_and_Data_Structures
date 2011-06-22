#include "sorting_template.h"
#include <iostream>
#include <list>
using namespace std;

void test_sorting_template() {
	vector<int> v;
	for (int i = 1; i <=30; i++) {
		v.push_back(i*10);
	}
	random_shuffle(v.begin(), v.end());
	cout << "Before sorting: " << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	std::cout << std::endl;
	
	//merge_sort(v.begin(), v.end());
	//insertion_sort(v.begin(), v.end());
	//selection_sort(v.begin(), v.end());
	//bubble_sort(v.begin(), v.end());
	//quick_sort(v.begin(), v.end());
	counting_sort(v.begin(), v.end());
	
	cout << "After sorting: " << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	std::cout << std::endl;
}

