#include <cstddef> //for size_t

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
		void push(const T& t);
		T& pop();
		void traverse(void (*f)(T&));
	
	private:
		T m_data[SIZE];
		size_t m_size;
};

void test_stack();

