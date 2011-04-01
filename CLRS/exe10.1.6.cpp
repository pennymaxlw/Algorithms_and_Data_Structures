#include "stack.h"

static void print(int &i)
{
	cout << i << " ";
}

template<typename T, size_t SIZE> 
class Squeue
{
	public:
		Squeue() {}
		~Squeue() {}
		
		size_t size()
		{
			return m_stackin.size() + m_stackout.size();
		}

		void enqueue(const T &t)
		{
			m_stackin.push(t);
		}

		const T& dequeue()
		{
			if (m_stackout.empty())
			{		
				while (!m_stackin.empty())
				{
					const T &t = m_stackin.top();
					m_stackout.push(t);
					m_stackin.pop();
				}			
			}

			const T &t= m_stackout.top();
			m_stackout.pop();
			return t;
		}

		void traverse(void (*f)(T &t))
		{
			m_stackin.traverse(f);
			m_stackout.traverse(f);
			cout << endl;
		}

	private:
		Stack<T, SIZE> m_stackin;
		Stack<T, SIZE> m_stackout;
};


int main()
{
	const size_t SIZE = 10;
	Squeue<int, SIZE> sq;
	
	for (size_t i = 0; i != SIZE; i++)
	{
		try
		{
			sq.enqueue(i);
		}
		catch (std::underflow_error &e)
		{
			cout << e.what() << endl;
		}
	}
	sq.traverse(print);
	cout << "size: " << sq.size() << endl;

	sq.dequeue();
	sq.dequeue();
	sq.dequeue();
	sq.traverse(print);
	cout << "size: " << sq.size() << endl;
	
	sq.enqueue(10);
	sq.enqueue(11);
	sq.enqueue(12);
	sq.traverse(print);
	//sq.enqueue(13);
	cout << "size: " << sq.size() << endl;
}
