#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


//=========================================
//			Sorting Functions
//=========================================

void swap(int &i, int &j)
{
	int t = i;
	i = j;
	j = t;
}

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
	for (int k = p; k <= r; k++)
	{
		if (i < ltn && (j >= rtn || ltv[i] <= rtv[j])) //notice inner brackets sequence 
			in[k] = ltv[i++];
		else
			in[k] = rtv[j++];
	}	
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

//=========================================
//			Testing
//=========================================

typedef void (*pFn)(vector<int>&);
enum Permutation {Ascend, Descend, Random};

void print_v(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void make_array_ascend(vector<int> &in)
{
	int i = 0;
	for (vector<int>::iterator it = in.begin();
			it != in.end(); it++, i++)
	{
		*it = i;
	}
}

void make_array_descend(vector<int> &in)
{
	int i = in.size() - 1;
	for (vector<int>::iterator it = in.begin();
			it != in.end(); it++, i--)
	{
		*it = i;
	}
}

void make_array_random(vector<int> &in)
{
	srand(static_cast<unsigned> (time(0)));
	for (vector<int>::iterator it = in.begin();
			it != in.end(); it++)
	{
		*it = rand()%(in.size());
	}
}

void call_sorting(vector<int> &in, pFn f, Permutation perm = Descend, bool if_print = true)
{
	switch (perm)
	{
	case Ascend:
		cout << "Ascend array:" << endl;
		make_array_ascend(in);
		break;
	case Descend:
		cout << "Descend array:" << endl;
		make_array_descend(in);
		break;
	case Random:
		cout << "Randomized array:" << endl;
		make_array_random(in);
		break;
	default:
		cerr << "Wrong permutation type!!" << endl;
		exit(1);
		break;
	}
	
	if (if_print) 
		print_v(in);
	
	long start = clock();	
	f(in);
	long end = clock();	
	double duration = static_cast<double> (end - start)/CLOCKS_PER_SEC; 

	cout << "After sorting array: " << endl;
	if (if_print) 
		print_v(in);
	cout << "Time consuming: " << duration << " seconds" << endl;
	cout << endl;
}

void test(pFn f)
{
	//while (1)
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
		vector<int> in(n, 0);

		bool if_print = true;
		string s;
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

		call_sorting(in, f, Ascend, if_print);
		call_sorting(in, f, Descend, if_print);
		call_sorting(in, f, Random, if_print);

		//cout << "\nLet's do it again..." << endl;
	}
}


int main()
{
	pFn f = NULL;
/*
	cout << "=========== Insertion sort ==========" << endl;
	f = insertion_sort;
	test(f);
	
	cout << "=========== Selection sort ==========" << endl;
	f = selection_sort;
	test(f);
*/	
	cout << "=========== Merge sort ==========" << endl;
	f = merge_sort;
	test(f);
}
