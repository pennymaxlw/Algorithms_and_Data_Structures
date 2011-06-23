#include "sorting_template.h"
#include <iostream>
#include <list>
using namespace std;

int hash(int val) {
	return val / 4;
}

void test_sorting_template() {
	//vector<int> v;
	//for (int i = 1; i <=30; i++) {
	//	v.push_back(i*15);
	//}
	vector<string> v;
	v.push_back("aaa");
	v.push_back("aab");
	v.push_back("aba");
	v.push_back("abb");
	v.push_back("abc");
	
	random_shuffle(v.begin(), v.end());
	cout << "Before sorting: " << endl;
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
	std::cout << std::endl;
	
	//merge_sort(v.begin(), v.end());
	//insertion_sort(v.begin(), v.end());
	//selection_sort(v.begin(), v.end());
	//bubble_sort(v.begin(), v.end());
	//quick_sort(v.begin(), v.end());
	//counting_sort(v.begin(), v.end());
	//bucket_sort(v.begin(), v.end(), hash);
	//radix_count(v.begin(), v.end(), 3, RadixInt());
	radix_count(v.begin(), v.end(), 3, RadixString());
	
	cout << "After sorting: " << endl;
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
	std::cout << std::endl;
}

