#include <iostream>
#include <vector>
using namespace std;

int binary_searching_iterative(vector<int> &in, int key)
{
	int i = 0, j = in.size() - 1, k = 0;
	
	while (i <= j)
	{
		k = (i + j)/2;
		if (key == in[k])
			return k;
		else if (key < in[k])
			j = k - 1;
		else
			i = k + 1;
	}
	return -1;
}

int binary_searching_recursive(vector<int> &in, int key, int i, int j)
{
	if (i > j)
		return -1;
	int k = (i + j)/2;
	if (key == in[k])
		return k;
	else if (key < in[k])
		return binary_searching_recursive(in, key, i, k - 1);
	else
		return binary_searching_recursive(in, key, k + 1, j);
} 

int main()
{
	const int N = 1000;
	int n = 0;
	vector<int> in;
	while(n < 1000)
		in.push_back(n++);

	int key = -1;
	int ret = -1;
	while (1)
	{
		cout << "Input key: ";
		cin >> key;
		if (cin.eof())
			return 0;
		else if (cin.fail() || key < 0)
		{
			cerr << "Invalid input!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			ret = binary_searching_iterative(in, key);
			cout << "iterative binary searching result: " << ret << endl;
			ret = binary_searching_recursive(in, key, 0, in.size() - 1);
			cout << "recursive binary searching result: " << ret << endl;
		}
	}
}
