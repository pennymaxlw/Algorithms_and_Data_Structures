#include "queue.h"

template<typename T, size_t SIZE>
class Qstack
{
	public:
		Qstack() {}
		~Qstack() {}

		void push(const T &t)
		{
			m_qin.enqueue(t);
		}

		T pop()
		{
			if (m_qin.empty() && m_qout.empty())
				throw std::underflow_error("Qstack underflow!!");

			T t;
			if (!m_qin.empty())
			{	
				while (!m_qin.empty())
				{
					t = m_qin.front();
					m_qin.dequeue();
					if (m_qin.size() == 0)
						break;
					m_qout.enqueue(t);
				}
			}
			else
			{
				while (!m_qout.empty())
				{
					t = m_qout.front();
					m_qout.dequeue();
					if (m_qout.size() == 0)
						break;
					m_qin.enqueue(t);
				}
			}
			return t;
		}

	private:
		Queue<T, SIZE> m_qin;
		Queue<T, SIZE> m_qout;
};

int main()
{
	Qstack<int, 6> qstack;
	cout << "push: 1" << endl;
	qstack.push(1);
	cout << "push: 2" << endl;
	qstack.push(2);
	cout << "push: 3" << endl;
	qstack.push(3);
	cout << "push: 4" << endl;
	qstack.push(4);
	cout << "push: 5" << endl;
	qstack.push(5);
	
	int t = 0;
	t = qstack.pop();
	cout << "pop: " << t << endl;
	t = qstack.pop();
	cout << "pop: " << t << endl;
	t = qstack.pop();
	cout << "pop: " << t << endl;
	
	cout << "push: 6" << endl;
	qstack.push(6);
	t = qstack.pop();
	cout << "pop: " << t << endl;
	t = qstack.pop();
	cout << "pop: " << t << endl;
	t = qstack.pop();
	cout << "pop: " << t << endl;
	t = qstack.pop();
	cout << "pop: " << t << endl;
	t = qstack.pop();
	cout << "pop: " << t << endl;
}
