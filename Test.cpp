#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;
int main() {

	BinaryTree<string, int>* Test_tree = new BinaryTree<string, int>();

	size_t Tree_size = 10;
	for (size_t i = 0; i  <Tree_size; i++)
	{
		Test_tree->Insert("i",i+1);
	}
	Test_tree->PrintTree(Test_tree->GetRoot(),Test_tree->height());

	Test_tree->Balance();
	Test_tree->PrintTree(Test_tree->GetRoot(), Test_tree->height());
	
	IDictionary<string, int>* IDic = new IDictionary<string, int>;
	IDic->Add("test",1);
	//IDic->Tree->PrintTree(Test_tree->GetRoot(), Test_tree->height());

	return 0;
}