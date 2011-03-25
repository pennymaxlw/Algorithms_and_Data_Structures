//2.3-7 
//Describe a O(nlgn)-time algorithm that, given a set S of n integers and another integer x, 
//determines whether or not there exist two elements in S whose sum is exactly x.

#include "sorting.h"
#include "helper.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// make two arrays
void find_pairs_with_same_sum(vector<int> &in, int sum)
{
	vector<int> v1(in);
	vector<int> v2;	
	for (int i = 0; i < v1.size(); i++)
		v2.push_back(sum - v1[i]);

	vector<int>::iterator oldend = v1.end();
	vector<int>::iterator newend = unique(v1.begin(), v1.end());
	v1.erase(newend, oldend);
	
	oldend = v2.end();
	newend = unique(v2.begin(), v2.end());
	v2.erase(newend, oldend);

	merge_sort(v1);
	merge_sort(v2);

	vector<int> v12;
	int i = 0, j = 0;
	while (i < v1.size() && j < v2.size())
	{
		if (j > v2.size() || v1[i] <= v2[j])
			v12.push_back(v1[i++]);
		else
			v12.push_back(v2[j++]);
	}
	//print_v(v12);

	for (int i = 0, j = 1; j < v12.size(); i++, j++)
	{
		if (v12[j] == v12[i])
			cout << "Found pair: " << v12[i] << ", " << sum - v12[i] << endl;
	}
}

// binary search
void find_pairs_with_same_sum2(vector<int> &in, int sum)
{
	vector<int> v(in);	
	
	merge_sort(v);
	//cout << "after sorting: " << endl;
	//print_v(v);

	// binary search
	int i, j, m;
	int key;
	for (int k = 0; k < v.size(); k++)
	{
		key = sum - v[k];
		i = 0, j = v.size() - 1;
		while (i <= j)
		{
			m = (j + i)/2;
			//cout << m << endl;
			//system("sleep 1");
			if (key == v[m])
			{
				if (m != k)
					cout << "Found pair: " << key << ", " << sum - key << endl;
				break;
			}
			else if (key < v[m])
				j = m - 1;
			else
				i = m + 1;
		}
	}
}

int main()
{
	const int sz = 6;
	int tmp[sz] = {3,4,5,6,7,8};
	vector<int> in(tmp, tmp + sz);
	const int sum = 6;
	
	cout << "\nMethod: two arrays " << endl;
	find_pairs_with_same_sum(in, sum);
	
	cout << "\nMethod: binary search " << endl;
	find_pairs_with_same_sum2(in, sum);

	return 0;
}
