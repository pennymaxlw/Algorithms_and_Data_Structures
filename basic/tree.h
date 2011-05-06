#ifndef TREE_H_
#define TREE_H_

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
using namespace std;

template<typename T> class BinTreeNode;

template<typename T>
class Visitor
{
	public:
		virtual ~Visitor() {}
		virtual void visit(BinTreeNode<T>* p) = 0;
};

template<typename T>
class PrintVisitor : public Visitor<T>
{
	public:
		~PrintVisitor() {}
		void visit(BinTreeNode<T>* p)
		{
			cout << p->data << "(" << p->left_n << ")" << " ";	
		}
};

template<typename T>
class DeleteVisitor : public Visitor<T>
{
	public:
		~DeleteVisitor() {}
		void visit(BinTreeNode<T>* p)
		{
			delete p;
		}
};

template<typename T>
class Add1Visitor : public Visitor<T>
{
	public:
		Add1Visitor(size_t n = 0) : num(n) {}
		~Add1Visitor() {}
		void visit(BinTreeNode<T>* p)
		{
			++num;			
		}
		size_t get_num() 
		{
			return num;
		}
	private:
		size_t num;
};

template<typename> class BinTree;

template<typename T>
class BinTreeNode
{
	public:
		BinTreeNode() : left(NULL), right(NULL), left_n(0) {}
		BinTreeNode(const T& e, BinTreeNode* l = NULL, BinTreeNode* r = NULL) 
			: data(e), left(l), right(r) {}
	
	public:
		T data;
		BinTreeNode* left;
		BinTreeNode* right;
		size_t left_n; 		// optional
};

template<typename T>
class BinTree
{
	public:
		BinTree(BinTreeNode<T>* p = NULL) : root(p) {}
		~BinTree() {destroy(); root = NULL;}
		bool empty() const
		{
			return root == NULL ? true : false;
		}
		void pre_order(Visitor<T>& visitor)
		{
			pre_order(visitor, root);
		}
		void in_order(Visitor<T>& visitor)
		{
			in_order(visitor, root);
		}
		void post_order(Visitor<T>& visitor)
		{
			post_order(visitor, root);
		}
		void pre_order_iterative(Visitor<T>& visitor)
		{
			pre_order_iterative(visitor, root);
		}
		void in_order_iterative(Visitor<T>& visitor)
		{
			in_order_iterative(visitor, root);
		}
		void post_order_iterative(Visitor<T>& visitor)
		{
			post_order_iterative(visitor, root);
		}
		void make_tree(const T& e, BinTree<T>& l, BinTree<T>& r);
		void break_tree(const T& e, BinTree<T>& l, BinTree<T>& r);
		void level_order(Visitor<T>& visitor);
		void display_compact(int width);
		void display_compact_connector(int width);
		void display_expand(int width);
		size_t height() const
		{
			return height(root) - 1; // need to subtract 1 because root height is 0
		}
		size_t size();
		BinTree* clone();
	
	private:
		void pre_order(Visitor<T>& visitor, BinTreeNode<T>* node);
		void in_order(Visitor<T>& visitor, BinTreeNode<T>* node);
		void post_order(Visitor<T>& visitor, BinTreeNode<T>* node);
		void pre_order_iterative(Visitor<T>& visitor, BinTreeNode<T>* node);
		void in_order_iterative(Visitor<T>& visitor, BinTreeNode<T>* node);
		void post_order_iterative(Visitor<T>& visitor, BinTreeNode<T>* node);
		size_t height(const BinTreeNode<T>* p) const;
		void destroy();
		void get_all_left_n(Add1Visitor<T>& visitor, BinTreeNode<T>* node);
		BinTreeNode<T>* clone(BinTreeNode<T>* node);

	private:
		BinTreeNode<T>* root;
};

void test_bintree();

template<typename T>
void BinTree<T>::make_tree(const T& e, BinTree<T>& l, BinTree<T>& r)
{
	if (!empty())
	{
		throw runtime_error("Making tree on an existing tree!");
	}
	
	root = new BinTreeNode<T>(e, l.root, r.root);
	l.root = r.root = NULL;
}

template<typename T>
void BinTree<T>::break_tree(const T& e, BinTree<T>& l, BinTree<T>& r)
{
	if (empty())
	{
		throw runtime_error("Breaking a NULL tree!");
	}

	e = root->data;
	l.root = root->left;
	r.root = root->right;
	delete root;
}

template<typename T>
void BinTree<T>::pre_order(Visitor<T>& visitor, BinTreeNode<T>* node)
{
	if (node)
	{
		visitor.visit(node);
		pre_order(visitor, node->left);
		pre_order(visitor, node->right);
	}
}

template<typename T>
void BinTree<T>::in_order(Visitor<T>& visitor, BinTreeNode<T>* node)
{
	if (node)
	{
		in_order(visitor, node->left);
		visitor.visit(node);
		in_order(visitor, node->right);
	}
}

template<typename T>
void BinTree<T>::post_order(Visitor<T>& visitor, BinTreeNode<T>* node)
{
	if (node)
	{
		post_order(visitor, node->left);
		post_order(visitor, node->right);
		visitor.visit(node);
	}
}

template<typename T>
void BinTree<T>::pre_order_iterative(Visitor<T>& visitor, BinTreeNode<T>* node)
{
	if (empty())
	{
		return;
	}

	stack<BinTreeNode<T>*> stk;
	BinTreeNode<T>* curr = node;

	while (!stk.empty() || curr)
	{
		if (curr)
		{
			visitor.visit(curr);
			stk.push(curr);
			//cout << "push: " << curr->data << endl;
			curr = curr->left;
		}
		else
		{
			curr = stk.top();
			stk.pop();
			//cout << "pop: " << curr->data << endl;
			curr = curr->right;
		}
	}
}

template<typename T>
void BinTree<T>::in_order_iterative(Visitor<T>& visitor, BinTreeNode<T>* node)
{
	if (empty())
	{
		return;
	}

	stack<BinTreeNode<T>*> stk;
	BinTreeNode<T>* curr = node;

	while (!stk.empty() || curr)
	{
		if (curr)
		{
			stk.push(curr);
			//cout << "push: " << curr->data << endl;
			curr = curr->left;
		}
		else
		{
			curr = stk.top();
			stk.pop();
			//cout << "pop: " << curr->data << endl;
			visitor.visit(curr);
			curr = curr->right;
		}
	}
}

template<typename T>
void BinTree<T>::post_order_iterative(Visitor<T>& visitor, BinTreeNode<T>* node)
{
	if (empty())
	{
		return;
	}

	stack<BinTreeNode<T>*> stk;
	BinTreeNode<T>* curr = node;
	BinTreeNode<T>* last = NULL;

	while (!stk.empty() || curr)
	{
		if (curr)
		{
			stk.push(curr);
			//cout << "push: " << curr->data << endl;
			curr = curr->left;
		}
		else
		{
			curr = stk.top();
			if (!curr->right || curr->right == last)	
			{
				visitor.visit(curr);
				stk.pop();
				last = curr;
				curr = NULL;
			}
			else
			{
				curr = curr->right;	
			}
		}
	}
}

template<typename T>
void BinTree<T>::level_order(Visitor<T>& visitor)
{
	queue<BinTreeNode<T>*> que;
	BinTreeNode<T>* p = root;
	while (p)
	{
		visitor.visit(p);
		if (p->left)
		{
			que.push(p->left);
		}
		if (p->right)
		{
			que.push(p->right);
		}
		if (!que.empty())
		{
			p = que.front();
			que.pop();
		}
		else
		{
			p = NULL;
		}
	}
}
template<typename T>
size_t BinTree<T>::height(const BinTreeNode<T>* p) const
{
	if (!p)
	{
		return 0;
	}

	size_t hl = height(p->left);
	size_t hr = height(p->right);
	return (hl > hr) ? ++hl : ++hr;
}

template<typename T>
size_t BinTree<T>::size()
{
	Add1Visitor<T> v;
	pre_order(v);	
	return v.get_num();
}

template<typename T>
void BinTree<T>::destroy()
{
	DeleteVisitor<T> v;
	post_order(v);
}

template<typename T>
struct NodePos
{
	BinTreeNode<T>* node;
	int pos;
};

template<typename T>
struct NodeDis
{
	BinTreeNode<T>* node;
	char connector;
};


template<typename T>
void BinTree<T>::get_all_left_n(Add1Visitor<T>& visitor, BinTreeNode<T>* node)
{
	if (node)
	{
		get_all_left_n(visitor, node->left);
		node->left_n = visitor.get_num();
		visitor.visit(node);
		get_all_left_n(visitor, node->right);
	}	
}

// width: how many characters
// pos: proportional with width(not for single character)
template<typename T>
void BinTree<T>::display_compact_connector(int width)
{
	Add1Visitor<T> v;
	get_all_left_n(v, root);
	//PrintVisitor<T> print_v;
	//in_order(print_v, root);
	//cout << endl;
	//return;
	deque<NodeDis<T> > que;
	NodeDis<T> np = {root, '#'};
	NodeDis<T> flag = {NULL, '#'};
	que.push_back(np);
	que.push_back(flag);
	size_t pos = 0;
	
	while (!que.empty())
	{
		np = que.front();
		que.pop_front();

		if (!np.node) // if NULL, which means it's end of a level
		{
			cout << "\n";
			if (!que.empty())
			{
				pos = 0;
				typename deque<NodeDis<T> >::iterator it;
				for (it = que.begin(); it != que.end(); it++)
				{
					//cout << "diff: " << it->node->left_n - pos << endl;
					for (int i = 0; i < it->node->left_n - pos; i++)
					{
						cout << setw(width) << " "; 
					}
					cout << setw(width) << it->connector;
					pos = it->node->left_n + 1;
				}
				cout << "\n";
				
				que.push_back(flag);
			}
			pos = 0;
		}
		else
		{
			for (int i = 0; i < np.node->left_n - pos; i++)
			{
				cout << setw(width) << " "; 
			}
			cout << setw(width) << np.node->data;
			//cout << setw(width) << np.connector;
			pos = np.node->left_n + 1;
			if (np.node->left)
			{
				NodeDis<T> tmp = {np.node->left, '/'};
				que.push_back(tmp);
			}
			if (np.node->right)
			{
				NodeDis<T> tmp = {np.node->right, '\\'};
				que.push_back(tmp);
			}
		}
	}
}

// width: how many characters
// pos: proportional with width(not for single character)
template<typename T>
void BinTree<T>::display_compact(int width)

{
	Add1Visitor<T> v;
	get_all_left_n(v, root);
	//PrintVisitor<T> print_v;
	//in_order(print_v, root);
	//cout << endl;
	//return;
	queue<BinTreeNode<T>*> que;
	que.push(root);
	que.push(NULL);
	BinTreeNode<T>* p = NULL;
	size_t pos = 0;
	
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (!p) // if NULL, which means it's end of a level
		{
			cout << "\n";
			if (!que.empty())
			{
				que.push(NULL);
				pos = 0;
			}
		}
		else
		{
			//cout << "pos: " << pos;
			for (int i = 0; i < p->left_n - pos; i++)
			{
				cout << setw(width) << " "; 
			}
			cout << setw(width) << p->data;
			pos = p->left_n + 1;
			if (p->left)
			{
				que.push(p->left);
			}
			if (p->right)
			{
				que.push(p->right);
			}
		}
	}
}

template<typename T>
void BinTree<T>::display_expand(int width)
{
	if (!root)
	{
		return;
	}

	queue<NodePos<T> > que;
	NodePos<T> flag = {NULL, -1};
	size_t sz = pow(2, height() + 1) - 1;
	NodePos<T> np = {root, sz / 2 + 1};
	que.push(np);
	que.push(flag);
	size_t pos = 0; 
	sz = sz / 2;

	while (!que.empty())
	{
		np = que.front();
		que.pop();

		if (!np.node)
		{
			cout << "\n";
			if (!que.empty())
			{
				que.push(flag);
			}
			sz = sz / 2;
			pos = 0;
		}
		else
		{
			//cout << "data: " << np.node->data << " np.pos: " << np.pos << endl;
			//cout << "diff: " << np.pos - pos - 1 << endl;
			for (int i = 0; i < np.pos - pos - 1; i++)
			{
				cout <<  setw(width) << " ";
			}
			pos = np.pos; //???????
			cout << setw(width) << np.node->data;
			if (np.node->left)
			{
				NodePos<T> tmp = {np.node->left, np.pos - sz / 2 - 1};			
				que.push(tmp);
			}
			if (np.node->right)
			{
				NodePos<T> tmp = {np.node->right, np.pos + sz / 2 + 1};			
				que.push(tmp);
			}
		}
	}
}

template<typename T>
BinTreeNode<T>* BinTree<T>::clone(BinTreeNode<T>* node)
{
	if (node)
	{
		BinTreeNode<T>* l = clone(node->left);
		BinTreeNode<T>* r = clone(node->right);
		BinTreeNode<T>* np = new BinTreeNode<T>(node->data, l, r);
		//cout << "clone data: " << node->data << endl;
		return np;
	}	
	return NULL;
}

template<typename T>
BinTree<T>* BinTree<T>::clone()
{
	BinTreeNode<T>* pn = clone(root);
	BinTree<T>* p = new BinTree<T>(pn);
	return p;
}

#endif






