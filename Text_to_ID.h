#pragma once
#include "BinaryTree_IDictionary.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ListSequence.hpp"
#include <sstream>
using namespace std;

void Print(Sequence<string>* seq, const int& length) {
	cout << "It is your sequence: " << endl;
	for (int i = 0; i < length; i++) {
		cout <<seq->Get(i) << " ";
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
	
}

ListSequence<string>* write_to_list() {
	string text;
	ListSequence<string>* list = new ListSequence<string>();
	cout << "Please, paste you text: "<<endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, text);
	cout << text << endl;
	string word;
	stringstream s;
	s.str(text);
	while (!s.eof()) {
		s >> word;
		list->Prepend(word);
	}
	return list;

}
ListSequence<string>* return_list() {
	cout << "How do you want to enter your text?" << endl << "1.By hand" << endl << "2.From file" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) {
		ListSequence<string>* words = write_to_list();
		return words;
	}
	else {
		ListSequence<string>* words = text_to_list();
		return words;
	}
}

void create_ID(ListSequence<string>* words, int size_of_pages_words) {
	IDictionary<string, int>* IDic = new IDictionary<string, int>();
	int page_number = 1;
	int cur_size = 0;
	int count_of_pages = 0;

	int  wordscopy = words->GetLength();
	wordscopy -= (int)(size_of_pages_words / 2);
	++count_of_pages;

	// count of pages
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


	// if all words on first page
	if (count_of_pages == 1) {
		while (cur_size != words->GetLength()) {
			IDic->Add(words->Get(cur_size), 1);
			cur_size++;
			--a;
		}
	}  // if not
	else {

		for (int i = 0; i < count_of_pages; i++) {
			if (page_number == 1) {
				for (int j = 0; j < (int)(size_of_pages_words / 2) && (a >= 0); j++) {
					IDic->Add(words->Get(cur_size), page_number);
					cur_size++;
					--a;
				}
			}
			else if ((page_number % 5) == 0) {
				for (int j = 0; j < (int)(size_of_pages_words * 3 / 4) && (a > 0); j++) {
					IDic->Add(words->Get(cur_size), page_number);
					cur_size++;
					--a;
				}
			}

			else {
				for (int j = 0; j < size_of_pages_words && (a > 0); j++) {
					IDic->Add(words->Get(cur_size), page_number);
					cur_size++;
					--a;
				}
			}
			page_number++;
		}
	}
	cout << "It is your IDictionary: " << endl;
	IDic->PrintItems();
}
