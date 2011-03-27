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

