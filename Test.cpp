#include "BinaryTree_IDictionary.h"
#include <iostream>
#include <string>
using namespace std;
int main() {

	/*BinaryTree<string, int>* Test_tree = new BinaryTree<string, int>();

	size_t Tree_size = 10;
	for (size_t i = 0; i  <Tree_size; i++)
	{
		Test_tree->Insert("i",i+1);
	}
	Test_tree->PrintTree(Test_tree->GetRoot(),Test_tree->height());

	Test_tree->Balance();
	Test_tree->PrintTree(Test_tree->GetRoot(), Test_tree->height());*/
	
	IDictionary<string, int>* IDic = new IDictionary<string, int>;
	IDic->Add("test1",1);
	IDic->Add("test2", 2);
	IDic->Add("test3", 2);
	//IDic->Tree->PrintTree(Test_tree->GetRoot(), Test_tree->height());
	IDic->Tree->Balance();
	IDic->PrintAll();
	//cout<<IDic->ContainsKey("test2");
	IDic->Remove("test3");
	IDic->PrintAll();
	//cout<<IDic->Tree->Height();
	
	return 0;
}