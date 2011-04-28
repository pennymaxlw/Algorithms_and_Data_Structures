#include "tree.h"

void test_tree()
{
	BinaryTree<char>* ptree = NULL;
	cout << "build tree..." << endl;
	BinaryTree<char>::build_tree_preorder(ptree);
	cout << "traverse tree..." << endl;
	ptree->depth_first_traversal();
	cout << endl;
}
