#include <vector>
using namespace std;

class Heap
{
	public:
		Heap(vector<int> &v) : m_v(v) {m_size = m_v.size();}
		~Heap() {}
		int left(int i) {return 2*i + 1;}
		int right(int i) {return 2*i + 2;}
		int parent(int i) {return (i - 1)/2;}
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

class Max_Priority_Queue : public Max_Heap
{
	public:
		Max_Priority_Queue(vector<int> &v);
		~Max_Priority_Queue() {}
		int maximum() {return m_v[0];}
		int extract_max();
		void increase_key(int i, int key);
		void insert(int key);
};
