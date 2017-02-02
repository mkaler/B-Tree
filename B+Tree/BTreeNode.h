#pragma once
class BTreeNode
{
	private:
		int *keys;  // An array of keys
		int t;      // Minimum degree (defines the range for number of keys)
		BTreeNode **C; // An array of child pointers
		int n;     // Current number of keys
		bool leaf; // Is true when node is leaf. Otherwise false
	public:
		BTreeNode();
		~BTreeNode();
		BTreeNode(int _t, bool _leaf);   // Constructor

		/* A utility function to insert a new key in the subtree rooted with
		   this node. The assumption is, the node must be non-full when this
		   function is called*/
		void insertNonFull(int k);

		// A utility function to split the child y of this node. i is index of y in
		// child array C[].  The Child y must be full when this function is called
		void splitChild(int i, BTreeNode *y);

		// A function to traverse all nodes in a subtree rooted with this node
		void traverse();

		// A function to search a key in subtree rooted with this node.
		BTreeNode *search(int k);   // returns NULL if k is not present.

		void remove(int k);
		// Make BTree friend of this so that we can access private members of this
		// class in BTree functions
		int findKey(int k);
		void removeFromLeaf(int idx);
		void removeFromNonLeaf(int idx);
		int getPred(int idx); 
		int getSucc(int idx);
		void merge(int idx);
		void fill(int idx);
		void borrowFromPrev(int idx);
		void borrowFromNext(int idx);
		friend class BTree;
};

