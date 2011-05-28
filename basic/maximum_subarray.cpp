#include "helper.h"
#include "maximum_subarray.h"
#include <iostream>
#include <vector>
using namespace std;

int maximum_subarray_bruteforce(vector<int> &in, int &lo, int &hi)
{
	lo = hi = 0;
	int max = in[0], sum = 0;

	for (int j = 0; j < in.size(); j++)
	{
		sum = 0;
		for (int i = j; i < in.size(); i ++)
		{
			sum += in[i];
			if (sum > max)
			{
				max = sum;
				lo = j;
				hi = i;
			}
		}
	}
	return max;
}

int maximum_subarray_dp(vector<int> &in, int &lo, int &hi)
{
	int sum = in[0];
	int max = sum;
	lo = hi = 0;
	int start = 0;
	for (int i = 1; i < in.size(); i++)
	{
		sum += in[i];
		if (sum > max)
		{
			max = sum;
			hi = i;
			lo = start;
		}
			
		if (sum < 0)
		{
			sum = 0;
			if (i < in.size() - 1)
				start = i + 1;
		}
	}
	return max;
}

int maximum_subarray_dp2(vector<int> &in, int &lo, int &hi)
{
	int sum_min = in[0];
	int sum = in[0];
	int max = in[0];
	int tmp = 0;
	lo = hi = 0;

	for (int i = 1; i < in.size(); i++)
	{
		sum += in[i];
		tmp = sum - sum_min;
		if (tmp > 0)
		{	
			if (tmp > max)
			{
				max = tmp;
			}
		}
		else
		{
			sum_min = sum;
		}
	}
	return max;
}

typedef int (*pFn) (vector<int>&, int&, int&);

void test_maximum_subarray_func(pFn f)
{
	int lo, hi, max;

	cout << "== Test case 1 ==" << endl;
	int arr[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	vector<int> in(arr, arr + 16);
	max = f(in, lo, hi);
	cout << "Array: " << endl; print_v(in);
	cout << "Maximum sum: " << max << endl;
	cout << "Range: " << lo << " - " << hi << endl; 
	
	cout << "== Test case 2 ==" << endl;
	int arr2[6] = {-30,-25,-3,-16,-23,-4};
	vector<int> in2(arr2, arr2 + 6);
	cout << "Array: " << endl; print_v(in2);
	max = f(in2, lo, hi);
	cout << "Maximum sum: " << max << endl;
	cout << "Range: " << lo << " - " << hi << endl; 
	
	cout << "== Test case 3 ==" << endl;
	int arr3[6] = {13,25,3,46,23,4};
	vector<int> in3(arr3, arr3 + 6);
	cout << "Array: " << endl; print_v(in3);
	max = f(in3, lo, hi);
	cout << "Maximum sum: " << max << endl;
	cout << "Range: " << lo << " - " << hi << endl; 
}

void test_maximum_subarray()
{
	pFn f = 0;

	cout << "\n======== DP method =========" << endl;
	f = maximum_subarray_dp;
	test_maximum_subarray_func(f);
	
	cout << "\n======== DP method2 =========" << endl;
	f = maximum_subarray_dp2;
	test_maximum_subarray_func(f);
	
	cout << "\n======== brute-force method =========" << endl;
	f = maximum_subarray_bruteforce;
	test_maximum_subarray_func(f);
}
