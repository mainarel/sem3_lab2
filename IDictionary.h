//#pragma once
//#include "BinaryTree.h"
//
//template <class TKey, class TElement>
//class IDictionary {
//private:
//	int Capacity;
//	int Count;
//
//public:
//	BinaryTree<TKey, TElement>* Tree;
//	IDictionary(int capacity) {
//		this->Capacity = capacity;
//		this->Count = 0;
//		this->Tree = new BinaryTree<TKey, TElement>();
//	}
//
//	int GetCapacity() {
//		return this->Capacity;
//	}
//	int GetCount() {
//		return this->Count;
//	}
//
//	TElement Get(TKey key) {
//		
//			TElement value = this->Tree->FindNode(key);
//		if (node != nullptr) {
//			return node->value;
//		}
//		else return NULL;
//	}
//
//	bool ContainsKey(TKey key) {
//		return this->Tree->toCheck(key);
//	}
//
//	void Add(TKey key, TElement element) {
//		this->Tree->Insert(key, element);
//		++this->Count;
//	}
//
//	void Remove(TKey key) {
//		this->Tree->RemoveNode(key);
//		return;
//	}
//};