#ifndef BS_TREE_H_
#define BS_TREE_H_

#include "bin_tree.h"
template<typename T>
class BSTree : public BinTree<T>
{
	using BinTree<T>::empty;
	using BinTree<T>::root;
	public:
		bool search(const T& key, T& e) const;
		bool minimum(T& e) const;
		bool maximum(T& e) const;
		BSTree<T>& insert(const T& key);
		BSTree<T>& del(const T& key);
};

void test_bs_tree();

template<typename T>
bool BSTree<T>::search(const T& key, T& e) const
{
	BinTreeNode<T>* p = this->root;
	while (p)
	{
		if (key == p->data)
		{
			e = p->data;
			return true;
		}
		
		if (key < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;	
		}
	}
	return false;
}

template<typename T>
bool BSTree<T>::minimum(T& e) const
{
	if (empty())
	{
		return false;
	}
	BinTreeNode<T>* p = this->root;
	while (p->left)
	{
		p = p->left;
	}
	
	if (p)
	{
		e = p->data;
		return true;
	}
	return false;
}

template<typename T>
bool BSTree<T>::maximum(T& e) const
{
	if (empty())
	{
		return false;
	}
	BinTreeNode<T>* p = this->root;
	while (p->right)
	{
		p = p->right;
	}
	
	if (p)
	{
		e = p->data;
		return true;
	}
	return false;
}

template<typename T>
BSTree<T>& BSTree<T>::insert(const T& key)
{
	BinTreeNode<T>* p = this->root;
	BinTreeNode<T>* pp = this->root;
	while (p)
	{
		pp = p;
		if (key <= p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}

	p = new BinTreeNode<T>(key);
	if (!pp)
	{
		this->root = p;
	}
	else
	{
		if (key <= pp->data)
		{
			pp->left = p;	
		}
		else
		{
			pp->right = p;
		}
	}
	return *this;
}

template<typename T>
BSTree<T>& BSTree<T>::del(const T& key)
{
	if (empty())
	{
		return *this;
	}
	// first find position
	BinTreeNode<T>* p = this->root;
	BinTreeNode<T>* pp = NULL;
	while (p && key != p->data)
	{
		pp = p;
		if (key < p->data)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	
	if (!p)
	{
		cout << "No such key!!" << endl;
		return *this;
	}

	// p has both left and right
	if (p->left && p->right)
	{
		// convert to 0 or 1 child case
		// find largest in left sub-tree
		BinTreeNode<T> *s = p->left,
					*ps = p;
		while (s->right)
		{
			ps = s;
			s = s->right;
		}

		// move s to p
		p->data = s->data;
		p = s;
		pp = ps;
	}

	// no child or 1 child from here
	BinTreeNode<T>* c = NULL;
	if (p->left)
	{
		c = p->left;
	}
	else
	{
		c = p->right;
	}

	if (p == root)
	{
		root = c;
	}
	else
	{
		if (p == pp->left)
		{
			pp->left = c;	
		}
		else
		{
			pp->right = c;
		}
	}
	
	delete p;

	return *this;
}

#endif
