#include "list.h"
#include "helper.h"
#include <iostream>
using namespace std;

void test_list()
{
	List<int> list;
	
	for (int i = 0; i < 100; i++)
		list.insert(i);

	list.traverse(print_int);
	cout << endl;

	list.clear();
	list.traverse(print_int);
	cout << endl;
}
