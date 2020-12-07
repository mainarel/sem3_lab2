#pragma once
#include <string>
#include <iostream>
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

		void InsertNode(TKey new_key, TValue new_value) {
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
		static size_t height(TreeNode<TKey,TValue>* node)
		{
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
		size_t height()
		{
			return height(this->root);
		}

		void PrintTree(TreeNode<TKey,TValue>* node, size_t level)
		{
			if (node)
			{
				PrintTree(node->left, level + 1);
				for (int i = 0; i < level - this->height(); i++) cout << "                ";
				cout << "[" << level - this->height() << "] ";
				cout <<"Key: "<< node->GetKey() <<"  Value: " <<node->GetValue() << endl;
				PrintTree(node->right, level + 1);
			}
		}

		
		int _size(TreeNode <TKey, TValue>* subTree) //return # of items stored in container.
		{
			int res = 0;
			if (subTree == nullptr) return 0;
			res += _size(subTree->GetLeft());
			res += _size(subTree->GetRight());
			return res + 1;
		}
		int  Size()
		{
			return _size(root);
		}
	
		void Clear()
		{
			_clear(root);
			root = nullptr;
		}
		void _clear(TreeNode <TKey, TValue>* cur)
		{
			if (cur == nullptr) return;
			_clear(cur->GetLeft());
			_clear(cur->GetRight());
			delete cur;
		}


		//balance
		void DSW() {
			if (nullptr != root) {
				createBackbone();
				createBalancedBT();
			}
		}

		void createBackbone() {
			TreeNode<TKey, TValue>* grandParent = nullptr;
			TreeNode<TKey, TValue>* parent = root;
			TreeNode<TKey, TValue>* leftChild;

			while (nullptr != parent) {
				leftChild = parent->left;
				if (nullptr != leftChild) {
					grandParent = rotateRight(grandParent, parent, leftChild);
					parent = leftChild;
				}
				else {
					grandParent = parent;
					parent = parent->right;
				}
			}
		}

		TreeNode<TKey, TValue>* rotateRight(TreeNode<TKey, TValue>* grandParent, TreeNode<TKey, TValue>* parent, TreeNode<TKey, TValue>* leftChild) {
			if (nullptr != grandParent) {
				grandParent->right = leftChild;
			}
			else {
				root = leftChild;
			}
			parent->left = leftChild->right;
			leftChild->right = parent;
			return grandParent;
		}

		void createBalancedBT() {
			int n = 0;
			for (TreeNode<TKey, TValue>* tmp = root; tmp != nullptr; tmp = tmp->right) {
				n++;
			}

			int m = greatestPowerOf2LessThanN(n + 1) - 1;
			makeRotations(n - m);

			while (m > 1) {
				makeRotations(m /= 2);
			}
		}

		int greatestPowerOf2LessThanN(int n) {
			int x = MSB(n);
			return (1 << x);
		}

		int MSB(int n) {
			int ndx = 0;
			while (1 < n) {
				n = (n >> 1);
				ndx++;
			}
			return ndx;
		}

		void makeRotations(int bound) {
			TreeNode<TKey, TValue>* grandParent = nullptr;
			TreeNode<TKey, TValue>* parent = root;
			TreeNode<TKey, TValue>* child = root->right;
			for (; bound > 0; bound--) {
				if (child != nullptr && child->right != nullptr) {
					rotateLeft(grandParent, parent, child);
					grandParent = child;
					parent = grandParent->right;
					child = parent->right;
				}
				else {
					break;
				}
			}
		}

		void rotateLeft(TreeNode<TKey, TValue>* grandParent, TreeNode<TKey, TValue>* parent, TreeNode<TKey, TValue>* rightChild) {
			if (nullptr != grandParent) {
				grandParent->right = rightChild;
			}
			else {
				root = rightChild;
			}
			parent->right = rightChild->left;
			rightChild->left = parent;
		}

		///////////////////
		
	
		TreeNode<TKey, TValue>* _balance(TreeNode <TKey, TValue>* itemList, int small, int large) //return the pointer of the root.
		{
			int mid = (small + large) / 2;
			if (small > large) return nullptr;
			TreeNode <TKey, TValue>* newRoot = new TreeNode <TKey, TValue>(itemList[mid].ref_key(), itemList[mid].ref_item());
			newRoot->SetLeft(_balance(itemList, small, (mid - 1)));
			newRoot->SetRight(_balance(itemList, (mid + 1), large));
			return newRoot;
		}

	
		void Trav_Inorder(TreeNode<TKey, TValue>* itemList, TreeNode <TKey, TValue>* cur, int& index)
		{
			if (cur == nullptr) return;
			Trav_Inorder(itemList, cur->GetLeft(), index);
			itemList[index] = *cur;
			index++;
			Trav_Inorder(itemList, cur->GetRight(), index);
		}

		void Balance()
		{
			int index = 0;
			int num = Size();
			TreeNode <TKey, TValue>* itemList = new TreeNode <TKey, TValue>[num]();
			Trav_Inorder(itemList, root, index);
			Clear();
			root = _balance(itemList, 0, num - 1);
			delete[] itemList;
		}

	
		TValue& operator[](const TKey& key)
		{
			TreeNode <TKey, TValue>* cur = root;
			if (root == nullptr)
			{
				root = new TreeNode <TKey, TValue>;
				root->SetKey(key);
				return root->ref_item();
			}

			while (cur != nullptr)
			{
				if (cur->ref_key() == key) return cur->ref_item();
				else if (cur->ref_key() > key)
				{
					if (cur->GetLeft() != nullptr) cur = cur->GetLeft();
					else
					{
						cur->SetLeft(new TreeNode <TKey, TValue>);
						cur->GetLeft()->SetKey(key);
						return cur->GetLeft()->ref_item();
					}
				}
				else
				{
					if (cur->GetRight() != nullptr) cur = cur->GetRight();
					else
					{
						cur->SetRight(new TreeNode <TKey, TValue>);
						cur->GetRight()->setKey(key);
						return cur->GetRight()->ref_item();
					}
				}
			}
		}
		/*

		void setKey(const TKey& new_key) {
			key = new_key;
		}

		TreeNode<TKey, TValue>* getLeft() const {
			return left;
		}
		TreeNode<TKey, TValue>* getRight() const {
			return right;
		}

		TKey& ref_key() {
			return key;
		}

		TValue& ref_item() {
			return value;
		}

		bool operator == (const TreeNode<TKey, TValue>& a) {
			if (key = a.ref_key())
				return true;
			else
				return false;
		}

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
	
