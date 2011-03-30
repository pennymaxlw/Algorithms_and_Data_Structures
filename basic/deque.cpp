#include "deque.h"

static void print(int &t)
{
	cout << t << " ";
}

void test_deque()
{
	const size_t SIZE = 10;
	Deque<int, SIZE> deque;

	cout << "--> testing push_back..." << endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		try
		{
			deque.push_back(i);
		}
		catch (std::overflow_error &e)
		{
			cout << "i: " << i << endl;
			cout << e.what() << endl;
		}
	}
	deque.traverse(print);
	cout << endl;
	cout << "size: " << deque.size() << endl;
	deque.print_mark();

	cout << "--> testing pop_back..." << endl;
	while (!deque.empty())
	{
		deque.pop_back();
	}
	deque.traverse(print);
	cout << endl;
	cout << "size: " << deque.size() << endl;
	deque.print_mark();
	
	cout << "--> testing push_front..." << endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		try
		{
			deque.push_front(i);
		}
		catch (std::overflow_error &e)
		{
			cout << "i: " << i << endl;
			cout << e.what() << endl;
		}
	}
	deque.traverse(print);
	cout << endl;
	cout << "size: " << deque.size() << endl;
	deque.print_mark();
	
	cout << "--> testing pop_front..." << endl;
	while (!deque.empty())
	{
		deque.pop_front();
	}
	deque.traverse(print);
	cout << endl;
	cout << "size: " << deque.size() << endl;
	deque.print_mark();
}
