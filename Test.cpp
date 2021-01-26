#include "BinaryTree_IDictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListSequence.hpp"
#include "Text_to_ID.h"
#include "Vecor_matrix.h"
using namespace std;
int main() {
	
	/////////////////////////////////////////////////////
	 int size;
	 int choose;
	////////////////////////////////////////////////////
	 cout << "1. Alphabetical index  \n2. Sparse vectors and matrices"<<endl;
	 cin >> choose;
	 switch (choose) {
	 case 1: {
		 cout << "Maximum page length type: " << endl << "1. Number of symbols" << endl << "2. Number of words" << endl;
		 cin >> choose;
		 int a = 0;
		 cout << "Enter the size of pages: " << endl;
		 cin >> size;
		 while (size <= 0) {
			 cout << "Count cannot be zero or negative, try again " << endl;
			 cin >> size;
		 }
		 create_ID(return_list(), size, choose);
	 }
	 case 2: { 
		 cout << "1. Make sprace vector \n2. Make sprace matrix " << endl;
		 cin >> choose;
		 if (choose == 1) {
			 
			 Print_svm<int,int>(make_sprace_vector<int,int>(new_vector<int>()));
			 
		 }
		 if (choose == 2) {
			// new_matrix<string>();
			 Print_sprace_matrix<string>(make_sprace_matrix(new_matrix<string>()));
		 }
	 }
	 }
	
	return 0;
}