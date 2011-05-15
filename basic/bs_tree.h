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
		bool successor(const T& key, T &e) const;
		bool predecessor(const T& key, T &e) const;
		BSTree<T>& insert(const T& key);
		BSTree<T>& del(const T& key);
		T lca(const T& key1, const T& key2)
		{
			BinTreeNode<T>* ret = NULL;
			lca(key1, key2, root, ret);
			if (ret)
			{
				return ret->data;
			}
			else
			{
				return T();
			}
		}
	protected:
		bool search_node_by_key(const T& key, BinTreeNode<T>& nd) const;
		int lca(const T& key1, const T& key2, BinTreeNode<T>* p, BinTreeNode<T> *&ret);
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

template<typename T>
bool BSTree<T>::search_node_by_key(const T& key, BinTreeNode<T>& nd) const
{
	BinTreeNode<T>* p = root;
	
	while (p && p->data != key)
	{
		key <= p->data ? p = p->left : p = p->right;
	}

	if (p)
	{
		nd = *p;	
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool BSTree<T>::successor(const T& key, T &e) const
{
	BinTreeNode<T>* p = root;
	BinTreeNode<T>* pp = NULL;

	while (p && p->data != key)
	{
		if (key <= p->data)
		{ 
			// pp is the lowest ancestor of key node 
			// whose left child is also an ancestor of key node
			pp = p;
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}

	if (!p)
	{
		return false;
	}
	else if (p->right) // if it has right sub-tree, successor is the minimum in right sub-tree
	{
		p = p->right;
		while (p->left)
		{
			p = p->left;
		}
		e = p->data;
		return true;
	}
	else if (pp)
	{
		e = pp->data;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool BSTree<T>::predecessor(const T& key, T &e) const
{
	return false;	
}

// 二叉树两个结点的最低共同父结点
template<typename T>
int BSTree<T>::lca(const T& key1, const T& key2, 
					BinTreeNode<T>* p, BinTreeNode<T> *&ret)
{
	if (p)
	{
		//cout << p->data << endl;
		int cnt1 = lca(key1, key2, p->left, ret);
		int cnt2 = lca(key1, key2, p->right, ret);
		int cnt = cnt1 + cnt2;
		if (cnt == 2 && !ret)
		{
			//cout << "found lca: " << p->data << endl;
			ret = p;
		}
		bool match = p->data ==key1 || p->data == key2;
		if (match || cnt)
		{
			if (match && cnt == 1)
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
	}
	return 0;
}

#endif
