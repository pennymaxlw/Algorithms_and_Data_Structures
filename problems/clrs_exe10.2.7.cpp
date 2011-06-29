#include "list.h"
#include "helper.h"
#include <iostream>
using namespace std;

template<typename T>
class MyList : public List<T>
{
	typedef Node<T> TNode;
	public:
		MyList() {}
		~MyList() {}
		void reverse()
		{
			if (!this->m_phead)
				return;
			TNode* p = this->m_phead;
			TNode* q = p->next;
			TNode* t = NULL;
			while (q != NULL)
			{
				t = q->next;
				q->next = p;
				p = q;
				q = t;
			}
			this->m_phead->next = NULL; //Don't forget this!!
			this->m_phead = p;
		}
};

int main()
{
	MyList<int> list;
	
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(8);
	list.traverse(print_int);
	cout << endl;

	cout << "reverse list..." << endl;
	list.reverse();
	list.traverse(print_int);
	cout << endl;
}
