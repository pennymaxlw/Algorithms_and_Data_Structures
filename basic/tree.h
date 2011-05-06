#ifndef TREE_H_
#define TREE_H_

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <queue>
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
			cout << p->data << " ";	
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
		BinTreeNode() : left(NULL), right(NULL) {}
		BinTreeNode(const T& e, BinTreeNode* l = NULL, BinTreeNode* r = NULL) 
			: data(e), left(l), right(r) {}
	
	public:
		T data;
		BinTreeNode* left;
		BinTreeNode* right;
};

template<typename T>
class BinTree
{
	public:
		BinTree() : root(NULL) {}
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
		void make_tree(const T& e, BinTree<T>& l, BinTree<T>& r);
		void break_tree(const T& e, BinTree<T>& l, BinTree<T>& r);
		void level_order(Visitor<T>& visitor);
		void display(Visitor<T>& visitor, int width);
		size_t height() const
		{
			return height(root) - 1; // need to subtract 1 because root height is 0
		}
		size_t size();
	
	private:
		void pre_order(Visitor<T>& visitor, BinTreeNode<T>* node);
		void in_order(Visitor<T>& visitor, BinTreeNode<T>* node);
		void post_order(Visitor<T>& visitor, BinTreeNode<T>* node);
		size_t height(const BinTreeNode<T>* p) const;
		void destroy();

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

// width: how many characters
// pos: proportional with width(not for single character)
template<typename T>
void BinTree<T>::display(Visitor<T>& visitor, int width)
{
	size_t h = height();
	size_t root_pos = (pow(2, h + 1) - 1)/ 2; // half of total number of nodes
	root_pos += root_pos / 2; // add some buffer width for better display 
	int step = root_pos / 2; 
	int pos = 0;
	queue<NodePos<T> > que;
	NodePos<T> np = {root, root_pos};
	NodePos<T> flag = {NULL, -1};
	que.push(np);
	que.push(flag);
	
	while (!que.empty())
	{
		np = que.front();
		que.pop();
		if (!np.node) // if NULL, which means it's end of a level
		{
			cout << endl;
			pos = 0;
			step /= 2;
			if (!que.empty())
			{
				que.push(flag);
			}
		}
		else
		{
			//cout << "np.pos: " << np.pos;
			for (int i = 0; i < np.pos - pos - 1; i++)
			{
				cout << setw(width) << " "; 
			}
			cout << setw(width) << np.node->data;
			pos = np.pos;
			if (np.node->left)
			{
				NodePos<T> tmp = {np.node->left, np.pos - step};
				que.push(tmp);
			}
			if (np.node->right)
			{
				NodePos<T> tmp = {np.node->right, np.pos + step};
				que.push(tmp);
			}
		}
	}
}


#endif
