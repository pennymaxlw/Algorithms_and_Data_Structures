#include "sorting.h"
#include "helper.h"
#include "heap.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


//=========================================
//			Sorting Functions
//=========================================

//==== Insertion sort
void insertion_sort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); ++i)
	{
		int key = arr[i];
		int j = i - 1;
		for (; j >= 0 && arr[j] > key; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

//==== Selection sort
void selection_sort(vector<int> &in)
{
	vector<int>::iterator it1;
	vector<int>::iterator it2;
	vector<int>::iterator it_min;

	for (it1 = in.begin(); it1 != in.end() - 1; it1++)
	{
		for (it2 = it1 + 1, it_min = it1; it2 != in.end(); it2++)
		{
			if (*it2 < *it_min)
				it_min = it2;
		}
		if (it_min != it1)
		{
			swap(*it1, *it_min);
		}
	}
}

//==== Merge sort
void merge_sort_merge(vector<int> &in, int p, int q, int r)
{
	int ltn = q - p + 1;
	int rtn = r - q;
	vector<int> ltv(ltn, 0);
	vector<int> rtv(rtn, 0);
	int i, j;

	for (i = 0; i < ltn; i++)
		ltv[i] = in[p + i];
	for (i = 0; i < rtn; i++)
		rtv[i] = in[q + 1 + i];

	i = j = 0;
	int k = p;
	while (i < ltn && j < rtn)
		ltv[i] <= rtv[j] ? in[k++] = ltv[i++] : in[k++] = rtv[j++];
	while (i < ltn)
		in[k++] = ltv[i++];
	while (j < rtn)
		in[k++] = rtv[j++];
}

void merge_sort_work(vector<int> &in, int p, int r)
{
	if (p < r)
	{
		int q = p + (r - p)/2;
		merge_sort_work(in, p, q);
		merge_sort_work(in, q + 1, r);
		merge_sort_merge(in, p, q, r);
	}
}

void merge_sort(vector<int> &in)
{
	merge_sort_work(in, 0, in.size() - 1);
}

//==== Bubble sort
void bubble_sort(vector<int> &in)
{
	for (int i = 0; i < in.size() - 1; i++)
		for (int j = in.size() - 1; j > i; j--)
		{
			if (in[j] < in[j - 1])
				swap(in[j], in[j - 1]);
		}
}

//==== Heap sort
void heap_sort(vector<int> &in)
{
	Max_Heap heap(in);
	heap.sort();
	in = heap.get_v();
}

//==== Quick sort
int partition(vector<int> &in, int p, int r, bool if_random = true)
{
	int m = p;
	if (if_random)
		m = p + rand()%(r - p);	

	//cout << "m: " << m << endl;
	swap(in[m], in[r]);
	int i = p;
	for (int j = p; j < r; j++)
	{
		if (in[j] <= in[r])
		{
			swap(in[i], in[j]);
			i++;
		}
	}
	swap(in[i], in[r]);
	return i;
}

void quick_sort_work(vector<int> &in, int p, int r)
{
	if (p < r)
	{
		int q = partition(in, p, r, true);
		quick_sort_work(in, p, q - 1);
		quick_sort_work(in, q + 1, r);
	}
}

void quick_sort(vector<int> &in)
{
	srand(static_cast<unsigned> (time(0)));
	quick_sort_work(in, 0, in.size() - 1);
}

//============
//==== Testing
//============

enum Permutation {Ascend, Descend, Random};
bool if_print = false;
vector<int> proto_ascend;
vector<int> proto_descend;
vector<int> proto_random;


void create_ascend_array(vector<int> &in, int n)
{
	for (int i = 0; i < n; i++)
		in.push_back(i);

	if (if_print) 
	{
		cout << "Unsorted ascend array:" << endl;
		print_v(in);
	}
}

void create_descend_array(vector<int> &in, int n)
{
	for (int i = 0; i < n; i++)
		in.push_back(n - 1 - i);

	if (if_print) 
	{
		cout << "Unsorted descend array:" << endl;
		print_v(in);
	}
}

void create_random_array(vector<int> &in, int n)
{
	srand(static_cast<unsigned> (time(0)));
	for (int i = 0; i < n; i++)
		in.push_back(rand()%n);

	if (if_print) 
	{
		cout << "Unsorted Random array:" << endl;
		print_v(in);
	}
}

void create_proto_arrays()
{
	int n = 10;
	while (1)
	{
		cout << "\nPlease input array size(N>0): ";
		cin >> n;
		if (cin.eof())
			exit(0);
		else if (cin.fail() || n < 0)
		{
			cerr << "Invalid value" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
			break;
	}

	string s;
	if (n > 1000)
		cout << "Too big N, will not display array elements!" << endl;
	else
	{
		while (1)
		{
			cerr << "Show arrays?(y/n): ";
			cin >> s;
			if (cin.eof())
				exit(0);
			else if (cin.fail() || (s[0] != 'y' && s[0] != 'n'))
			{
				cerr << "Invalid value" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else
			{
				s[0] == 'y' ? if_print = true : if_print = false;
				break;
			}
		}
	}

	create_ascend_array(proto_ascend, n);
	create_descend_array(proto_descend, n);
	create_random_array(proto_random, n);
}

void verify(vector<int> &in)
{
	for (vector<int>::iterator it = in.begin(); it != in.end() - 1; it++)
	{
		if (*it > *(it + 1))
		{
			for (int t = 0; t < 3; t++)
				cout << "!!! Failed to verify !!!";
			cout << endl;
			return;
		}
	}
	//cout << "Pass verification !!!" << endl;
}

void call_sorting(vector<int> &in, pFn f)
{
	long start = clock();	
	f(in);
	long end = clock();	
	double duration = static_cast<double> (end - start)/CLOCKS_PER_SEC; 

	verify(in);

	if (if_print) 
		print_v(in);
	cout << "Time: " << duration << " seconds" << endl;
}

void test_single_sorting(pFn f)
{
	vector<int> in_ascend(proto_ascend);
	cout << "Sorting ascend array, result:" << endl;
	call_sorting(in_ascend, f);

	vector<int> in_descend(proto_descend);
	cout << "Sorting descend array, result:" << endl;
	call_sorting(in_descend, f);

	vector<int> in_random(proto_random);
	cout << "Sorting random array, result:" << endl;
	call_sorting(in_random, f);
}

void test_sorting()
{
	pFn f = NULL;

	create_proto_arrays();

	cout << endl;
	cout << "\n=========== Insertion sort ==========" << endl;
	f = insertion_sort;
	test_single_sorting(f);

	cout << "\n=========== Selection sort ==========" << endl;
	f = selection_sort;
	test_single_sorting(f);

	cout << "\n=========== Merge sort ==========" << endl;
	f = merge_sort;
	test_single_sorting(f);

	cout << "\n=========== Bubble sort ==========" << endl;
	f = bubble_sort;
	test_single_sorting(f);

	cout << "\n=========== Heap sort ==========" << endl;
	f = heap_sort;
	test_single_sorting(f);

	cout << "\n=========== Quick sort ==========" << endl;
	f = quick_sort;
	test_single_sorting(f);
}
