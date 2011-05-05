#include "tree.h"

void test_bintree()
{
	BinTree<int> a, b, c, d, e, t;
	e.make_tree(5, t, t);
	d.make_tree(3, t, t);
	a.make_tree(1, d, e);
	b.make_tree(2, t, t);
	c.make_tree(4, a, b);
	
	PrintVisitor<int> v;
	cout << "Pre order" << endl;
	c.pre_order(v); 
	cout << endl;
	cout << "in order" << endl;
	c.in_order(v);
	cout << endl;
	cout << "post order" << endl;
	c.post_order(v);
	cout << endl;
	cout << "level order" << endl;
	c.level_order(v);
	cout << endl;
	
	cout << "size: " << c.size() << endl;

	cout << "height: " << c.height() << endl;
}
