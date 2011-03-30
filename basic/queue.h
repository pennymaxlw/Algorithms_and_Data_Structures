#ifndef _HDR_QUEUE_H_
#define _HDR_QUEUE_H_

#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T, size_t SIZE>
class Queue
{
	public:
		Queue() : m_head(0), m_tail(0) {}
		~Queue() {}

		size_t size() const
		{
			size_t s = 0;
			//m_head <= m_tail ? s = m_tail - m_head : s = SIZE - m_head + m_tail; 
			s = (m_tail - m_head + SIZE)%SIZE; 
			return s;
		}

		void clear()
		{
			m_head = m_tail = 0;
		}

		bool empty() const
		{
			return m_head == m_tail;
		}

		const T& front() const
		{
			return m_data[m_head];
		}

		void enqueue(const T& t) 
		{
			size_t pos = (m_tail + 1)%SIZE; 
			if (pos == m_head)
				throw std::overflow_error("Queue overflow!!");
			m_data[m_tail] = t; 
			m_tail = pos;
		}

		void dequeue()
		{
			if (empty())
				throw std::underflow_error("Queue underflow!!");
			m_head = (m_head + 1)%SIZE;
		}

		void traverse(void (*f)(T &t))
		{
			if (empty()) 
				return;
			size_t i = m_head; 
			while (i != m_tail)
			{
				f(m_data[i]);
				if (++i == SIZE) 
					i = i%SIZE;
			}
		}

		void print_mark()
		{
			cout << "head: " << m_head
				<< "  tail: " << m_tail << endl;
		}

	protected:
		T m_data[SIZE];
		size_t m_head;
		size_t m_tail;
};

void test_queue();

#endif
