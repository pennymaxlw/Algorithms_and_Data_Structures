#include "bin_tree.h"

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
	//e.make_tree(5, t, t);
	f.make_tree(6, l, m);
	//f.make_tree(6, t, m);
	g.make_tree(7, n, o);

	b.make_tree(2, d, e);
	c.make_tree(3, f, g);
	
	//a.make_tree(1, t, c);
	a.make_tree(1, b, c);
	
	cout << "\n****size: " << a.size() << endl;
	cout << "\n****height: " << a.height() << endl;

	PrintVisitor<int> v;
	cout << "\n****display tree, compact and connector" << endl;
	a.display_compact_connector(2);
	cout << "\n****display tree, compact" << endl;
	a.display_compact(2);
	cout << "\n****display tree, expand" << endl;
	a.display_expand(2);
	
	cout << "\n****pre order" << endl;
	a.pre_order(v); 
	cout << "\n****pre order iterative" << endl;
	a.pre_order_iterative(v);
	cout << endl;
	cout << "\n****in order" << endl;
	a.in_order(v);
	cout << "\n****in order iterative" << endl;
	a.in_order_iterative(v);
	cout << endl;
	cout << "\n****post order" << endl;
	a.post_order(v);
	cout << "\n****post order iterative" << endl;
	a.post_order_iterative(v);
	cout << endl;
	cout << "\n****level order" << endl;
	a.level_order(v);
	cout << endl;

	cout << "\n****clone tree" << endl;
	BinTree<int>* tp = a.clone();
	cout << "\n****display tree, compact and connector" << endl;
	tp->display_compact_connector(2);
	cout << "\n****in order" << endl;
	tp->in_order(v);
	cout << "\n****rotate" << endl;
	tp->rotate();
	cout << "\n****display tree, compact and connector" << endl;
	tp->display_compact_connector(2);
	delete tp;
}
