#include "helper.h"
#include <iostream>
using namespace std;

void swap(int &i, int &j)
{
	int t = i;
	i = j;
	j = t;
}

void print_v(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
