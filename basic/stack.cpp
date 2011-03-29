#include "stack.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T, size_t SIZE>
void Stack<T, SIZE>::push(const T& t)
{
	if (m_size >= SIZE)
		throw std::overflow_error("stack is overflow");
	m_data[m_size++] = t;
}

template<typename T, size_t SIZE>
T& Stack<T, SIZE>::pop()
{
	if (empty())
		throw std::underflow_error("stack is underflow");
	return m_data[--m_size];
}

template<typename T, size_t SIZE>
void Stack<T, SIZE>::traverse(void (*f)(T&))
{
	if (empty())
		return;
	for (size_t i = 0; i < m_size; i++)
		f(m_data[i]);
}

void print(int& i)
{
	cout << i << " ";
}

void test_stack()
{
	Stack<int, 5> stack;
	cout << "push 1" << endl; stack.push(1);
	cout << "push 2" << endl; stack.push(2);
	cout << "push 3" << endl; stack.push(3);
	cout << "push 4" << endl; stack.push(4);
	stack.traverse(print); cout << endl;
	cout << "pop "<< stack.pop() << endl;
	cout << "pop "<< stack.pop() << endl;
	cout << "pop "<< stack.pop() << endl;
	cout << "pop "<< stack.pop() << endl;
	stack.traverse(print); cout << endl;
	
	cout << "push 1" << endl; stack.push(1);
	cout << "push 2" << endl; stack.push(2);
	cout << "push 3" << endl; stack.push(3);
	cout << "push 4" << endl; stack.push(4);
	cout << "push 5" << endl; stack.push(5);
	stack.traverse(print); cout << endl;
	cout << "push 6" << endl; stack.push(6);
	stack.traverse(print); cout << endl;
}
