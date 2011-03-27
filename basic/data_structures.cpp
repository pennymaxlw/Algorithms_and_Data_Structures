#include "data_structures.h"
#include "helper.h"
#include <iostream>
using namespace std;

void Heap::build()
{
	//cout << m_size << endl;
	for (int i = m_size/2; i >= 0; i--)
	{
		//cout << "i: " << i << endl;
		heapify(i); 
		//print_v(m_v);	
	}
}

void Heap::sort()
{
	build();
	int len = m_v.size();
	for (int i = len - 1; i > 0; i--)
	{
		swap(m_v[0], m_v[i]);
		m_size--;
		heapify(0);
	}
}

void Max_Heap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int max = 0;
	if (l < m_size && m_v[l] > m_v[i])
		max = l;
	else
		max = i;
	if (r < m_size && m_v[r] > m_v[max])
		max = r;
	if (max != i)
	{
		//cout << "max: " << max << endl;
		swap(m_v[i], m_v[max]);
		heapify(max);
	}
}

bool Max_Heap::verify()
{
	for (int i = 0; i <= m_size/2; i++)
	{
		int l = left(i);
		int r = right(i);
		if (l < m_size && m_v[i] < m_v[l])
			return false;
		if (r < m_size && m_v[i] < m_v[r])
			return false;
	}
	return true;
}

void Min_Heap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int min = 0;
	if (l < m_size && m_v[l] < m_v[i])
		min = l;
	else
		min = i;
	if (r < m_size && m_v[r] < m_v[min])
		min = r;
	if (min != i)
	{
		//cout << "min: " << min << endl;
		swap(m_v[i], m_v[min]);
		heapify(min);
	}
}

bool Min_Heap::verify()
{
	for (int i = 0; i <= m_size/2; i++)
	{
		int l = left(i);
		int r = right(i);
		if (l < m_size && m_v[i] > m_v[l])
			return false;
		if (r < m_size && m_v[i] > m_v[r])
			return false;
	}
	return true;
}

Max_Priority_Queue::Max_Priority_Queue(vector<int> &v) : Max_Heap(v)
{
	build();
}

int Max_Priority_Queue::extract_max()
{
	if (m_size < 1)
	{
		cerr << "Heap underflow!!" << endl; 
		return -1; // not good...
	}
	int max = m_v[0];
	m_v[0] = m_v[m_size - 1];
	m_size--;
	heapify(0);
	return max;
}

void Max_Priority_Queue::increase_key(int i, int key)
{
	if (key < m_v[i])
	{
		cerr << "New key is smaller than current key!!" << endl;
		return;
	}
	m_v[i] = key;
	int p = 0;
	while (i > 0)
	{
		p = parent(i);
		if (m_v[p] < m_v[i])
		{
			swap(m_v[i], m_v[p]);
			i = p;
		}
		else
			break;
	}
}

void Max_Priority_Queue::insert(int key)
{
	m_size++;
	m_v[m_size - 1] = key - 1;
	increase_key(m_size, key);
}

int Max_Priority_Queue::del(int i)
{
	int key = m_v[i];
	m_v[i] = m_v[m_size -1];
	m_size--;
	heapify(i);
	return key;
}
