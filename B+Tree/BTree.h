#pragma once
#include "BTreeNode.h"
 class BTree
{
	private:
		BTreeNode *root; // Pointer to root node
		int t;  // Minimum degree
	public:
		BTree();
		~BTree();
		BTree(int t);
		void setT(int t);
		void traverse();// function to traverse the tree
		BTreeNode* search(int k);// function to search a key in this tree
		void insert(int k);// The main function that inserts a new key in this B-Tree
		void remove(int k);
		bool exists();
};

