#include "BinaryTree.h"
#include <iostream>
using namespace std;
int main() {

	BinaryTree<int, int>* Test_tree = new BinaryTree<int, int>();
    string str = "abcedbee";
	size_t Tree_size = 10;
	for (size_t i = 0; i  <Tree_size; i++)
	{
		Test_tree->InsertNode(i,i+1);
	}
	Test_tree->PrintTree(Test_tree->GetRoot(),Test_tree->height());
	//Test_tree->DSW();
	Test_tree->Balance();
	Test_tree->PrintTree(Test_tree->GetRoot(), Test_tree->height());

	return 0;
}