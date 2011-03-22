#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


//=========================================
//			Sorting Functions
//=========================================

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
	while (1)
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

		cout << "\nLet's do it again..." << endl;
	}
}


int main()
{
	pFn f = insertion_sort;
	test(f);
}
