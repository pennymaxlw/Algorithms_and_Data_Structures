#include "queue.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T, size_t SIZE>
const T& Queue<T, SIZE>::front() const
{
	return m_data[m_head];
}

template<typename T, size_t SIZE>
void Queue<T, SIZE>::enqueue(const T &t)
{
	if (full())
		throw std::overflow_error("Queue overflow!!");
	m_data[m_tail] = t; 
	m_tail = (m_tail + 1)%SIZE;
}

template<typename T, size_t SIZE>
void Queue<T, SIZE>::dequeue()
{
	if (empty())
		throw std::underflow_error("Queue underflow!!");
	m_head = (m_head + 1)%SIZE;
}

template<typename T, size_t SIZE>
void Queue<T, SIZE>::traverse(void (*f)(T &t))
{
	if (empty()) 
		return;
	for (size_t i = m_head; i != m_tail; i++)
	{
		if (i == SIZE) 
			i = i%SIZE;
		f(m_data[i]);
	}
}

template<typename T, size_t SIZE>
void Queue<T, SIZE>::print_mark()
{
	cout << "head: " << m_head
		<< "  tail: " << m_tail << endl;
}

static void print(int &t)
{
	cout << t << " ";
}

void test_queue()
{
	const size_t SIZE = 10;
	Queue<int, SIZE> queue;
	for (size_t i = 0; i < SIZE; i++)
	{
		try
		{
			queue.enqueue(i);
		}
		catch (std::overflow_error &e)
		{
			cout << e.what() << endl;
		}
	}
	queue.traverse(print);
	cout << endl;
	cout << "size: " << queue.size() << endl;
	queue.print_mark();

	queue.dequeue();
	queue.dequeue();
	queue.enqueue(9);
	queue.enqueue(10);
	queue.traverse(print);
	cout << endl;
	cout << "size: " << queue.size() << endl;
	queue.print_mark();

	while (!queue.empty())
	{
		int x = queue.front();
		cout << x << " ";
		queue.dequeue();
	}
	cout << endl;
	cout << "size: " << queue.size() << endl;
	queue.print_mark();
}
