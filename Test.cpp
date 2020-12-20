#include "BinaryTree_IDictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListSequence.hpp"
#include "Text_to_ID.h"
using namespace std;
int main() {
	
	/////////////////////////////////////////////////////
	 int size_of_pages_words;
	 int size_of_pages_symbols;
	 char mew = 'y';
	////////////////////////////////////////////////////
	 
	cout << "Enter the size of pages: " << endl;
	cin >> size_of_pages_words;
	while (size_of_pages_words <= 0) {
		cout << "Count cannot be zero or negative, try again "<<endl;
		cin >> size_of_pages_words;
	}
	create_ID(return_list(), size_of_pages_words);
	/*cout << "Do you want to see the list of words?  " << endl << "Enter 'y' for yes and another for 'not' "<<endl;
	cin >> mew;
	if (mew == 'y') {
		Print(return_list(), return_list()->GetLength());
	}*/
	
	

	  
	

	return 0;
}