#pragma once
#include <string>
#include <iostream>
#include "IDictionary.h"
using namespace std;

template <class TKey, class TValue>
class BinaryTree 
{
public:
	template <class TKey, class TValue>
	class TreeNode {

	public:
		TKey key;
		TValue value;
		TreeNode* left;
		TreeNode* right;
	public:
		TreeNode()
		{
			left = nullptr;
			right = nullptr;
		}
		TreeNode (TKey& new_key, TValue& new_value) {
			this->key = new_key;
			this->value = new_value;
			this->left = nullptr;
			this->right = nullptr;
		}
		TKey GetKey()
		{
		return this->key;
		}
		TValue GetValue() {
			return this->value;
		}
		void SetLeft(TreeNode<TKey, TValue>* const new_left) {
			left = new_left;
		}

		void SetRight(TreeNode<TKey, TValue>* const new_right) {
			right = new_right;
		}
		TreeNode<TKey, TValue>* GetLeft() const
		{
			return left;
		}

		TreeNode<TKey, TValue>* GetRight() const
		{
			return right;
		}
		void SetKey(const TKey& new_key) {
			key = new_key;
		}

		TKey& ref_key() {
			return key;
		}

		TValue& ref_item() {
			return value;
		}
	};
		TreeNode <TKey, TValue>* root;
public:
	BinaryTree()
	{
		this->root = nullptr;
	}

	BinaryTree(TreeNode<TKey,TValue>* root)
	{
		this->root = root;
	}

	TreeNode<TKey,TValue>* GetRoot()
	{
		return this->root;
	}
		void Insert(TKey new_key, TValue new_value) {
			TreeNode<TKey,TValue>* InsertNode = new TreeNode<TKey,TValue>(new_key,new_value);
			TreeNode<TKey, TValue>* st = this->root;
			TreeNode<TKey, TValue>* nxt = nullptr;

			while (st != nullptr) {
				nxt = st;
				if (new_key< st->GetKey()) {
					st = st->left;
				}
				else {
					st = st->right;
				}
			}

			if (nxt == nullptr) {
				this->root = InsertNode;
			}
			else {
				if (new_key < nxt->GetKey()) {
					nxt->left = InsertNode;
				}
				else {
					nxt->right = InsertNode;
				}
			}
		}
		static size_t height(TreeNode<TKey,TValue>* node){
			size_t L;
			size_t R;
			if (node->left == nullptr && node->right == nullptr)
			{
				return 0;
			}
			else
			{
				if (node->left != nullptr)
				{
					L = height(node->left) + 1;
				}
				else
				{
					L = 0;
				}
				if (node->right != nullptr)
				{
					R = height(node->right) + 1;
				}
				else
				{
					R = 0;
				}
			}
			if (L > R)
			{
				return L;
			}
			else
			{
				return R;
			}
		}
		size_t height()	{
			return height(this->root);
		}

		void PrintTree(TreeNode<TKey,TValue>* node, size_t level) {
		if (node)
			{
				PrintTree(node->left, level + 1);
				for (int i = 0; i < level - this->height(); i++) cout << "                ";
				cout << "[" << level - this->height() << "] ";
				cout <<"Key: "<< node->GetKey() <<"  Value: " <<node->GetValue() << endl;
				PrintTree(node->right, level + 1);
			}
		}

		int _getcount(TreeNode <TKey, TValue>* subTree) //return # of items stored in container.	
		{
			int res = 0;
			if (subTree == nullptr) return 0;
			res += _getcount(subTree->GetLeft());
			res += _getcount(subTree->GetRight());
			return res + 1;
		}
		int  GetCount() {
			return _getcount(root);
		}
	
		void Clear() {
			_clear(root);
			root = nullptr;
		}
		void _clear(TreeNode <TKey, TValue>* cur) {
			if (cur == nullptr) return;
			_clear(cur->GetLeft());
			_clear(cur->GetRight());
			delete cur;
		}
	
		TreeNode<TKey, TValue>* _balance(TreeNode <TKey, TValue>* itemList, int small, int large) //return the pointer of the root.
		{
			int mid = (small + large) / 2;
			if (small > large) return nullptr;
			TreeNode <TKey, TValue>* newRoot = new TreeNode <TKey, TValue>(itemList[mid].ref_key(), itemList[mid].ref_item());
			newRoot->SetLeft(_balance(itemList, small, (mid - 1)));
			newRoot->SetRight(_balance(itemList, (mid + 1), large));
			return newRoot;
		}

		void Trav_Inorder(TreeNode<TKey, TValue>* itemList, TreeNode <TKey, TValue>* cur, int& index) {
			if (cur == nullptr) return;
			Trav_Inorder(itemList, cur->GetLeft(), index);
			itemList[index] = *cur;
			index++;
			Trav_Inorder(itemList, cur->GetRight(), index);
		}

		void Balance(){
			int index = 0;
			int num = GetCount();
			TreeNode <TKey, TValue>* itemList = new TreeNode <TKey, TValue>[num]();
			Trav_Inorder(itemList, root, index);
			Clear();
			root = _balance(itemList, 0, num - 1);
			delete[] itemList;
		}

		TValue FindNode(TreeNode<TKey, TValue>* Node, TKey need_key) {
			if (this->root == nullptr)
				throw std::exception("Empty");
			if (this->key == need_key)
			{
				return Node->GetValue();
			}
			else
			{
				if (need_key < Node->key)
				{
					return FindNode(Node->left, need_key);
				}
				else
				{
					return FindNode(Node->right, need_key);
				}
			}
		}
		TValue FindNode(TKey key) {
			return FindNode(this->root, key);
		}
		
		void RemoveNode(const TKey& key) {
			//bool found = false;
			TreeNode <TKey, TValue>* cur = root, * parentPtr = nullptr;
			while (cur != nullptr)
			{
				if (cur->ref_key() == key)
				{
					//found = true;
					break;
				}

				else
				{
					parentPtr = cur;
					if (cur->ref_key() > key) cur = cur->GetLeft();
					else
						cur = cur->GetRight();
				}
			}

			/*if (!found)
			{
			  cout << key << "is not in the tree." << endl;
			  return;
			}*/

			// the remove node is a leaf.
			if ((cur->GetLeft() == nullptr) && (cur->GetRight() == nullptr))
			{
				if (parentPtr->GetLeft() == cur)
					parentPtr->SetLeft(nullptr);
				else
					parentPtr->SetRight(nullptr);
				delete cur;
				return;
			}

			// the remove node has one child.
			else if ((cur->GetLeft() == nullptr && cur->GetRight() != nullptr) || (cur->GetRight() == nullptr && cur->GetLeft() != nullptr))
			{
				if (parentPtr->GetLeft() == cur)
				{
					if (cur->GetLeft() != nullptr)
					{
						parentPtr->SetLeft(cur->GetLeft());
						delete cur;
					}
					else
						parentPtr->SetLeft(cur->GetRight());
					delete cur;
				}

				else
				{
					if (cur->GetLeft() != nullptr)
					{
						parentPtr->SetRight(cur->GetLeft());
						delete cur;
					}
					else
						parentPtr->SetRight(cur->GetRight());
					delete cur;
				}
			}

			// the remove node has two children.
			else if ((cur->GetLeft() != nullptr) && (cur->GetRight() != nullptr))
			{
				//replace the node with the largest node on its left subtree. 
				TreeNode <TKey, TValue>* leftLargest = cur->GetLeft();
				TreeNode <TKey, TValue>* leftLargestParent = nullptr;
				while (leftLargest->GetRight() != nullptr) // find the largest on the left subtree.
				{
					leftLargestParent = leftLargest;
					leftLargest = leftLargest->GetRight();
				}
				cur->SetKey(leftLargest->ref_key());
				if (leftLargest->GetLeft() == nullptr)// leftLargest is a leaf;
				{
					leftLargestParent->SetRight(nullptr);
					delete leftLargest;
				}

				else // leftLargest has one child on its left.
				{
					leftLargestParent->SetRight(leftLargest->GetLeft());
					delete leftLargest;
				}
			}
			return;
		}
		/*
		bool operator != (const TreeNode<TKey, TValue>& a) {
			return !(key == a.ref_key());
		}

		bool operator > (const TreeNode<TKey, TValue>& a) {
			if (key > a.ref_key())
				return true;
			else
				return false;
		}

		bool operator < (const TreeNode<TKey, TValue>& a) {
			return a.ref_key() > key;
		}

		bool operator >= (const TreeNode<TKey, TValue>& a) {
			return !(key < a.ref_key());
		}

		bool operator <= (const TreeNode<TKey, TValue>& a) {
			return !(key > a.ref_key());
		}*/
};
	
