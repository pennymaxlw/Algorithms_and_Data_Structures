#include "helper.h"
#include <iostream>
#include <vector>
using namespace std;

extern int merge_inversions(vector<int>&, int, int, int);

int counting_inversions(vector<int> &in, int lo, int hi)
{
	int invs = 0;
	if (lo < hi)
	{
		int mid = (lo + hi)/2;
		invs += counting_inversions(in, lo, mid);
		invs += counting_inversions(in, mid + 1, hi);
		cout << "before merge: "; print_v(in);
		cout << "lo: " << lo << " hi: " << hi << endl;
		invs += merge_inversions(in, lo, mid, hi);
	}

	//cout << "lo: " << lo << " hi: " << hi << " invs: " << invs << endl;
	return invs;
}

int merge_inversions(vector<int> &in, int lo, int mid, int hi)
{
	//cout << "lo: " << lo << " mid: " << mid << " hi: " << hi << endl;
	vector<int> ltv, rtv;
	int ltn = mid - lo + 1, rtn = hi - mid;
	int i;
	for (i = 0; i < ltn; i++)
		ltv.push_back(in[lo + i]);
	for (i = 0; i < rtn; i++)
		rtv.push_back(in[mid + 1 + i]);

	i = 0;
	int j = 0, k = lo;
	int invs = 0;
	while (i < ltn && j < rtn)
	{
		if (ltv[i] <= rtv[j])
			in[k++] = ltv[i++];
		else
		{
			invs += ltn - i;
			in[k++] = rtv[j++];
		}
	}
	while (j < rtn)
		in[k++] = rtv[j++];	
	while (i < ltn)
		in[k++] = ltv[i++];
	cout << "invs: " << invs << endl;
	return invs;
}

int main()
{
	const int N = 10;
	int tmp[N] = {1,2,3,4,5,12,7,11,9,10};
	//int tmp[N] = {2,3,8,6,1};
	vector<int> v(tmp, tmp + N);

	int invs = counting_inversions(v, 0, N - 1);
	cout << "after sorting: ";
	print_v(v);
	cout << "inversion count: " << invs << endl;

	return 0;
}
