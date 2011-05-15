#include "bs_tree.h"

void test_bs_tree()
{
	BSTree<int> tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(6);
	tree.insert(3);
	tree.insert(9);
	tree.insert(0);
	tree.insert(2);
	tree.insert(4);
	tree.insert(8);
	tree.insert(1);

	tree.display_compact_connector(2);

	tree.insert(15).insert(11);

	tree.display_compact_connector(2);
	
	int j = 3;
	cout << "\n****delete " << j << endl;
	tree.del(j);

	tree.display_compact_connector(2);

	cout << "\n***in order" << endl;;
	PrintVisitor<int> v;
	tree.in_order(v);
	
	int i;
	cout << "\n***max: ";
	if (tree.maximum(i))
	{
		cout << i << endl;
	}
	else
	{
		cerr << "not found!!" << endl;
	}
	
	cout << "\n***mini: ";
	if (tree.minimum(i))
	{
		cout << i << endl;
	}
	else
	{
		cerr << "not found!!" << endl;
	}

	cout << "\n***input successor: ";
	int s;
	while (cin >> i)
	{
		if (tree.successor(i, s))
		{
			cout << "successor is: " << s << endl;
		}
		else
		{
			cerr << "no successor" << endl;
		}
		cout << "\n***input successor: ";
	}
}
