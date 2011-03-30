#include "queue.h"
#include <iostream>
#include <stdexcept>
using namespace std;

//== Declaration
template<typename T, size_t SIZE>
class Deque : public Queue<T, SIZE>
{
	public:
		Deque() {}
		~Deque() {}
		const T& tail() const;
		void push_front(const T &t);
		void pop_front();
		void push_back(const T &t);
		void pop_back();
};

//== Definition
template<typename T, size_t SIZE>
void Deque<T, SIZE>::push_front(const T &t)
{
	int pos = this->m_head - 1;
	if (pos < 0)
		pos = SIZE - 1;
	if (pos == this->m_tail)
		throw std::overflow_error("Deque overflow!!");
	this->m_head = pos;
	this->m_data[this->m_head] = t;
}

template<typename T, size_t SIZE>
void Deque<T, SIZE>::pop_front()
{
	this->dequeue();
}

template<typename T, size_t SIZE>
void Deque<T, SIZE>::push_back(const T &t)
{	
	this->enqueue(t);
	//Queue<T, SIZE>::enqueue(t);
	this->size();
	//this->traverse();
}

template<typename T, size_t SIZE>
void Deque<T, SIZE>::pop_back()
{	
	if (this->empty())
		throw std::underflow_error("Deque underflow!!");
	int pos = this->m_tail - 1;
	if (pos < 0)
		pos = SIZE - 1;
	this->m_tail = pos;
}

template<typename T, size_t SIZE>
const T& Deque<T, SIZE>::tail() const
{
	if (this->empty())
		throw std::underflow_error("Deque underflow!!");
	int pos = this->m_tail - 1;
	if (pos < 0)
		pos = SIZE - 1;
	return this->m_data[pos];
}

void test_deque();
