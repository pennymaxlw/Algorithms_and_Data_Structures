#include "tree.h"

void test_bintree()
{
	BinTree<int> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, t;
	h.make_tree(8, t, t);
	i.make_tree(9, t, t);
	j.make_tree(10, t, t);
	k.make_tree(11, t, t);
	l.make_tree(12, t, t);
	m.make_tree(13, t, t);
	n.make_tree(14, t, t);
	o.make_tree(15, t, t);
	
	d.make_tree(4, h, i);
	e.make_tree(5, j, k);
	f.make_tree(6, l, m);
	g.make_tree(7, n, o);

	b.make_tree(2, d, e);
	c.make_tree(3, f, g);
	
	a.make_tree(1, b, c);
	
	PrintVisitor<int> v;
	cout << "display tree" << endl;
	a.display(v, 3);
	
	cout << "Pre order" << endl;
	a.pre_order(v); 
	cout << endl;
	cout << "in order" << endl;
	a.in_order(v);
	cout << endl;
	cout << "post order" << endl;
	a.post_order(v);
	cout << endl;
	cout << "level order" << endl;
	a.level_order(v);
	cout << endl;
	
	cout << "size: " << a.size() << endl;

	cout << "height: " << a.height() << endl;

}
