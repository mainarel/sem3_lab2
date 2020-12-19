#pragma once
#include "BinaryTree_IDictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListSequence.hpp"

void Print(Sequence<string>* seq, const int& length) {
	cout << "It is your sequence: " << endl;
	for (int i = 0; i < length; i++) {
		cout << seq->Get(i) << " ";
	}
	cout << endl;
}
ListSequence<string>* text_to_list () {
	ListSequence<string>* list = new ListSequence<string>();
	string word;
	ifstream in("C://Users/asus/Desktop/text.txt"); //file with text
	if (in.is_open()) {
		while (!in.eof()) {
			in >> word;
			list->Prepend(word);
		}
		in.close();
	}
	else { cout << "File didn't open: "; }
	return list;
	//Print(list, count);
}