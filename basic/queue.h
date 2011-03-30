#include <cstddef>

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
		bool full() const
		{
			return m_head == (m_tail + 1)%SIZE;
		}
		const T& front() const;
		void enqueue(const T& t);
		void dequeue();
		void traverse(void (*f)(T &t));
		void print_mark();
		void print_row();

	private:
		T m_data[SIZE];
		size_t m_head;
		size_t m_tail;
};

void test_queue();
