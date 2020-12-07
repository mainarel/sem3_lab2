#include "BinaryTree.h"
#include <iostream>
using namespace std;
int main() {

	BinaryTree<int, int>* Test_tree = new BinaryTree<int, int>();

	size_t Tree_size = 10;
	for (size_t i = 0; i  <Tree_size; i++)
	{
		Test_tree->Insert(i,i+1);
	}
	Test_tree->PrintTree(Test_tree->GetRoot(),Test_tree->height());

	Test_tree->Balance();
	Test_tree->PrintTree(Test_tree->GetRoot(), Test_tree->height());
	Test_tree->RemoveNode(6);
	Test_tree->PrintTree(Test_tree->GetRoot(), Test_tree->height());
	return 0;
}