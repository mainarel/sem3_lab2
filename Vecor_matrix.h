#pragma once
#include "BinaryTree_IDictionary.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "ArraySequence.hpp"
#include <utility>



template <class T>
void Print(Sequence<T>* seq, const int& length) {
	cout << "It is your sequence: " << endl;
	for (int i = 0; i < length; i++) {
		cout << "[" << seq->Get(i) << "]" << " ";
	}
	cout << endl;
}

template <class T>
ArraySequence<T>* new_vector() {
	ArraySequence<T>* vector = new ArraySequence<T>();
	T element;
	ifstream in("C://Users/asus/Desktop/vector.txt"); //file with vector
	if (in.is_open()) {
		while (!in.eof()) {
			in >> element;
			vector->Prepend(element);
		}
		in.close();
	}
	else { cout << "File didn't open: "; }
	return vector;
}

template <class T>
ArraySequence<ArraySequence<string>*>* new_matrix() {
	ArraySequence<string>* lines = new ArraySequence<string>();
	ArraySequence<ArraySequence<string>*>* matrix = new ArraySequence<ArraySequence<string>*>();
	//ArraySequence<string>* lines = new ArraySequence<string>();

	T element;
	ifstream in("C://Users/asus/Desktop/matrix.txt"); //file with matrix
	string s;
	int count_of_lines = 0;
	int count_of_elem = 0;
	if (in.is_open()) {
		while (!in.eof()) {
			while (getline(in, s)) {
				s += ' ';
				lines = new ArraySequence<string>(count_of_elem);
				while (s.find(" ") != string::npos) {

					if (count_of_lines != 0) {
						for (int i = 0; i < count_of_elem; i++) {
							lines->Set(i, s.substr(0, s.find(" ")));
							s.erase(0, s.find(' ') + 1);
						}
					}
					else {
						lines->Prepend(s.substr(0, s.find(" ")));
						s.erase(0, s.find(' ') + 1);
						count_of_elem++;
					}
				}
				matrix->Prepend(lines);
				count_of_lines++;
			}
			in.close();
			cout << "Number of columns - " << count_of_lines << endl;
		}
	}
	else { cout << "File didn't open: "; }

	Print(matrix->Get(0), matrix->Get(0)->GetLength() );
	Print(matrix->Get(1), matrix->Get(1)->GetLength() );
	Print(matrix->Get(2), matrix->Get(2)->GetLength() );
	//	cout << matrix->GetLength()-1 << endl;
	return matrix;
}


IDictionary<pair<long,long>, string>* make_sprace_matrix(ArraySequence<ArraySequence<string>*>* matrix) {
	IDictionary<pair<long, long>, string>* IDic = new IDictionary<pair<long, long>, string>();
	for (long i = 0; i < matrix->GetLength(); i++) {
		for (long j = 0; j < (matrix->Get(i))->GetLength() ; j++)
			if (matrix->Get(i)->Get(j) != "0") {
				pair<long, long> index = make_pair(i,j);
				//cout << index.first << index.second << endl;
				IDic->Add(index, matrix->Get(i)->Get(j));
			}
	}
	return IDic;
}

//template <class T>
template <class T, class TValue>
IDictionary<int, TValue>* make_sprace_vector(ArraySequence<T>* vector) {
	IDictionary<int, TValue>* IDic = new IDictionary<int, TValue>();
	for (long i = 0; i < vector->GetLength(); i++) {
		if (vector->Get(i) != 0) {
			IDic->Add(i, vector->Get(i));
		}
	}
	return IDic;
}


template <class T, class TValue>
void Print_svm(IDictionary<int, TValue>* IDic) {
	IDic->PrintItems();
}

template <class TValue>
void Print_sprace_matrix(IDictionary<pair<long,long>, TValue>* IDic) {
	IDic->PrintItems();
}
