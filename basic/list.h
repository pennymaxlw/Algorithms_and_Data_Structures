#include <iostream>

template<typename T>
struct Node
{
	Node():next(NULL) {}
	T data;
	Node* next;
};

template <typename T>
class List
{
	typedef Node<T> TNode;
	public:
		List():m_phead(NULL) {}
		~List()
		{
			clear();
		}

		void clear()
		{
			TNode* p = m_phead;
			TNode* q = NULL;
			while (p != NULL)
			{
				q = p->next;
				delete p;
				p = q;
			}
			m_phead = NULL;
		}

		void insert(const T &t)
		{
			TNode* p = new TNode;
			p->data = t;
			if (m_phead == NULL)
				m_phead = p;
			else
			{
				p->next = m_phead;
				m_phead = p;
			}
		}

		void traverse(void (*f)(const T &t))
		{
			TNode* p = m_phead;
			while (p != NULL)
			{
				f(p->data);	
				p = p->next;
			}
		}

		void reverse()
		{
			TNode* p = NULL;
			TNode* q = m_phead;
			TNode* r = NULL;
			while (q)
			{
				r = q->next;
				q->next = p;
				p = q;
				q = r;
			}
			m_phead = p;
		}

	private:
		TNode* m_phead;
};

void test_list();

