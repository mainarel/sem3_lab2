#include "BinaryTree_IDictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListSequence.hpp"
#include "Text_to_ID.h"
using namespace std;

int main() {
	
	IDictionary<string, int>* IDic = new IDictionary<string, int>;
	/*int size = 5;
	for (int i = 0; i < size; i++) {
		IDic->Add("test", i);
	}*/
	//IDic->PrintAsTree();
	//cout << "Tree after balance:" << endl;
	//IDic->PrintAsTree();
    //IDic->PrintItems();

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
	ListSequence<string>* words = text_to_list();
	cout << "Do you want to see the list of words?  " << endl << "Enter 'y' for yes and another for 'not' "<<endl;
	
	cin >> mew;
	if (mew == 'y') {
		Print(words, words->GetLength());
	}

	 int page_number=1;
	 int cur_size = 0;
	 int count_of_pages = 0;

	  int  wordscopy = words->GetLength();
	  wordscopy -= (int)(size_of_pages_words / 2);
	  ++count_of_pages;

	  if (wordscopy > 0) {
		  for (int i = wordscopy; i > 0; ) {
			  if ((count_of_pages % 10) == 0) {
				  i -= (int)(size_of_pages_words * 3 / 4);
			  }
			  else {
				  i -= size_of_pages_words;
			  }
			  ++count_of_pages;
		  }
	  }

	  cout << count_of_pages << endl;
	  cout << words->GetLength() << endl;
	  int a = words->GetLength();

	  for (int i = 0; i < count_of_pages; i++) {

		  if (page_number == 1) {
			  for (int j = 0; j < (int)(size_of_pages_words / 2) && (a >= 0); j++) {
				  IDic->Add(words->Get(cur_size), page_number);
				  cur_size++;
				  --a;
				  //if ()
			  }
		  }
		  else if ((page_number % 5 ) == 0) {
				 for (int j = 0; j < (int)(size_of_pages_words * 3 / 4) && (a > 0); j++) {
				  IDic->Add(words->Get(cur_size), page_number);
				  cur_size++;
				  --a;
			  }
		  }

		  else {
			  for (int j=0; j< size_of_pages_words && (a > 0); j++) {
				  IDic->Add(words->Get(cur_size), page_number);
				  cur_size++;
				  --a;
			  }
		  }
		  page_number++;

	  }
	  IDic->PrintItems();
	

	return 0;
}