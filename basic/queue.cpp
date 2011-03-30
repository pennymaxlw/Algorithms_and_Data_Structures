#include "queue.h"

static void print(int &t)
{
	cout << t << " ";
}

void test_queue()
{
	const size_t SIZE = 10;
	Queue<int, 30> queue;
	for (size_t i = 0; i < SIZE; i++)
	{
		try
		{
			queue.enqueue(i);
		}
		catch (std::overflow_error &e)
		{
			cout << "i: " << i << endl;
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
