#include <iostream>
using namespace std;

template<typename T>
class Tree
{
	public:
		virtual T* key() const = 0;
		//virtual Tree& subtree() const = 0;
		virtual void depth_first_traversal() const = 0;
		//virtual void breadth_first_traversal() const = 0;
};

template<typename T>
class BinaryTree : public Tree<T>
{
	public:
		BinaryTree();
		BinaryTree(const T &t);
		~BinaryTree();
		virtual T* key() const;
		virtual BinaryTree<T>*& left();
		virtual BinaryTree<T>*& right();
		//virtual Tree& subtree() const;
		virtual void depth_first_traversal() const;
		//virtual void breadth_first_traversal() const;
		static void build_tree_preorder(BinaryTree<T>*& ptree);

	private:
		T* m_pkey;
		BinaryTree* m_pleft;
		BinaryTree* m_pright;
};

void test_tree();

template<typename T>
BinaryTree<T>::BinaryTree():
  m_pkey(NULL),
  m_pleft(NULL), m_pright(NULL)	
{
}

template<typename T>
BinaryTree<T>::BinaryTree(const T &t):
	m_pkey(new T(t)),
	m_pleft(new BinaryTree()),
    m_pright(new BinaryTree())	
{
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	if (m_pkey)
		delete m_pkey;
	if (m_pleft)
		delete m_pleft;
	if (m_pright)
		delete m_pright;
	m_pkey = m_pleft = m_pright = NULL;
}

template<typename T>
T* BinaryTree<T>::key() const
{
	return m_pkey;
}

template<typename T>
BinaryTree<T>*& BinaryTree<T>::left()
{
	return m_pleft;
}

template<typename T>
BinaryTree<T>*& BinaryTree<T>::right() 
{
	return m_pright;
}

template<typename T>
void BinaryTree<T>::depth_first_traversal() const
{
	if (!m_pkey)
		return;
	m_pleft->depth_first_traversal();	
	cout << *m_pkey;
	m_pright->depth_first_traversal();	
}

template<typename T>
void BinaryTree<T>::build_tree_preorder(BinaryTree<T>*& ptree)
{
	T t;
	if( cin >> t, !cin.eof() )
	{
		ptree = new BinaryTree(t);
		build_tree_preorder(ptree->left());
		build_tree_preorder(ptree->right());
	}	
	else
	{
		ptree = new BinaryTree();
	}
}


