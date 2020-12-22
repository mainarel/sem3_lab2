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


int Length(ListSequence<string>* words)
{ 
	int length=0;
	for (int i = 0; i < words->GetLength(); i++) {
		length += words->Get(i).length();
	}
	
	length += words->GetLength() - 1;
	cout << "Length of string  - " << length << endl;
	return length;
}


void create_ID(ListSequence<string>* words, int number_of_smth, int choose) {

	IDictionary<string, int>* IDic = new IDictionary<string, int>();
	int page_number = 1;
	int cur_size = 0;
	int count_of_pages = 0;

	if (choose == 2) {
		int  wordscopy = words->GetLength();
		wordscopy -= (int)(number_of_smth / 2);
		++count_of_pages;

		if (wordscopy > 0) {
			for (int i = wordscopy; i > 0; ) {
				if ((count_of_pages % 10) == 0) {
					i -= (int)(number_of_smth * 3 / 4);
				}
				else {
					i -= number_of_smth;
				}
				++count_of_pages;
			}
		}
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
					for (int j = 0; j < (int)(number_of_smth / 2) && (a >= 0); j++) {
						IDic->Add(words->Get(cur_size), page_number);
						cur_size++;
						--a;
					}
				}
				else if ((page_number % 10) == 0) {
					for (int j = 0; j < (int)(number_of_smth * 3 / 4) && (a > 0); j++) {
						IDic->Add(words->Get(cur_size), page_number);
						cur_size++;
						--a;
					}
				}

				else {
					for (int j = 0; j < number_of_smth && (a > 0); j++) {
						IDic->Add(words->Get(cur_size), page_number);
						cur_size++;
						--a;
					}
				}
				page_number++;
			}
		}
	}
	else { //if numbers of symbols
		
		int length = Length(words);
		int  wordscopy = length;
		wordscopy -= (int)(number_of_smth / 2);
		++count_of_pages;

		if (wordscopy > 0) {
			for (int i = length; i > 0; ) {
				if ((count_of_pages % 10) == 0) {
					i -= (int)(number_of_smth * 3 / 4);
				}
				else {
					i -= number_of_smth;
				}
				++count_of_pages;
			}
		}
		cout << "Numbers of pages " << count_of_pages<< endl;

		int a = length; 
		// if all words on first page
		if (count_of_pages == 1) {
			for (int i = 0; i < number_of_smth && (a > 0); i + words->Get(i).length()) {
				IDic->Add(words->Get(cur_size), 1);
				cur_size++;
				a -= words->Get(i).length();
			}
		}  // if not
		else {

			for (int i = 0; i < count_of_pages; i++) {
				if (page_number == 1) {
					for (int j = 0; j < (int)(number_of_smth / 2) && (a > 0); j+ words->Get(i).length()+1) {
						IDic->Add(words->Get(cur_size), page_number);
						cur_size++;
						a -= words->Get(i).length()+1;
					}
				}
				else if ((page_number % 10) == 0) {
					for (int j = 0; j < (int)(number_of_smth * 3 / 4) && (a > 0); j + words->Get(i).length()+1) {
						IDic->Add(words->Get(cur_size), page_number);
						cur_size++;
						a -= words->Get(i).length()+1;
					}
				}

				else {
					for (int j = 0; j < number_of_smth && (a > 0); j +words->Get(i).length()+1) {
						IDic->Add(words->Get(cur_size), page_number);
						cur_size++;
						a -= words->Get(i).length()+1;
					}
				}
				page_number++;
			}
		}
	}
	//cout << count_of_pages << endl;


	cout << "It is your IDictionary: " << endl;
	IDic->PrintItems();

}
