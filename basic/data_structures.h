#include <vector>
using namespace std;

class Heap
{
	public:
		Heap(vector<int> &v) : m_v(v) {m_size = m_v.size();}
		~Heap() {}
		int left(int i) {return 2*i + 1;}
		int right(int i) {return 2*i + 2;}
		virtual void heapify(int i) = 0;
		void build();
		void sort();
		vector<int> get_v() {return m_v;}
		void reset() {m_size = m_v.size();}
	protected:
		vector<int> m_v;
		int m_size;
};

class Max_Heap : public Heap
{
	public:
		Max_Heap(vector<int> &v) : Heap(v) {}
		virtual void heapify(int i);
		~Max_Heap() {}
};

class Min_Heap : public Heap
{
	public:
		Min_Heap(vector<int> &v) : Heap(v) {}
		virtual void heapify(int i);
		~Min_Heap() {}
};
