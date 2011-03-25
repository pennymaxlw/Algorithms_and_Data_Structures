#include "sorting.h"
#include "helper.h"
#include <iostream>
#include <vector>
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
