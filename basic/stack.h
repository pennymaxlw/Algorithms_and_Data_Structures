#include <cstddef> //for size_t
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T, size_t SIZE>
class Stack
{
	public:
		Stack() : m_size(0) {}
		~Stack() {}
		bool empty() const 
		{
			return 0 == m_size;
		}
		
		size_t size() const
		{
			return m_size;
		}
		
		void clear()
		{
			m_size = 0;
		}
		
		const T& top()
		{
			if (empty())
				throw std::underflow_error("stack is underflow");
			return m_data[m_size - 1];
		}

		void push(const T& t)
		{
			if (m_size >= SIZE)
				throw std::overflow_error("stack is overflow");
			m_data[m_size++] = t;
		}

		void pop()
		{
			if (empty())
				throw std::underflow_error("stack is underflow");
			--m_size;
		}

		void traverse(void (*f)(T&))
		{
			if (empty())
				return;
			for (size_t i = 0; i < m_size; i++)
				f(m_data[i]);
		}
	
	private:
		T m_data[SIZE];
		size_t m_size;
};

void test_stack();

