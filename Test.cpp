#include "BinaryTree_IDictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListSequence.hpp"
#include "Text_to_ID.h"
using namespace std;
int main() {
	
	/////////////////////////////////////////////////////
	 int size;
	 int choose;
	////////////////////////////////////////////////////
	 cout << "Maximum page length type: " << endl << "1. Number of symbols" << endl << "2. Number of words" << endl;
	 cin >> choose;

	cout << "Enter the size of pages: " << endl;
	cin >> size;
	while (size <= 0) {
		cout << "Count cannot be zero or negative, try again "<<endl;
		cin >> size;
	}
	create_ID(return_list(), size, choose);
	/*cout << "Do you want to see the list of words?  " << endl << "Enter 'y' for yes and another for 'not' "<<endl;
	cin >> mew;
	if (mew == 'y') {
		Print(return_list(), return_list()->GetLength());
	}*/
	return 0;
}