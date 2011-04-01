#include "helper.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void swap(int &i, int &j)
{
	int t = i;
	i = j;
	j = t;
}

void print_int(const int &i)
{
	cout << i << " ";
}

void print_v(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void randomize_inplace(vector<int> &arr)
{
	srand(static_cast<unsigned> (time(0)));
	int n = arr.size();
	int r = 0;
	for (int i = 0; i < n - 1; i++)
	{
		r = i + rand()%(n - i);	
		swap(arr[i], arr[r]);
	}
}

void test_randomize_inplace()
{
	int i = 0;
	while (i++ < 10)
	{
		int tmp[10] = {0,1,2,3,4,5,6,7,8,9};
		vector<int> in(tmp, tmp + 10);
		randomize_inplace(in);
		system("sleep 1");
		print_v(in);
	}
}

//int main()
//{
//	test_randomize_inplace();
//}
