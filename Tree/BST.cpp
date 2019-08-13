#include <bits/stdc++.h>
using namespace std;

struct node
{
	int info;
	node* left;
	node* right; 

	node(int info)
	{
		this->info = info;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST
{
	node* root;

	public:

	BST()
	{
		root = NULL;
	}

	bool empty_t()
	{
		return root == NULL;
	}

	void insert_util(node **n, int e)
	{
		if(*n == NULL)
		{
			*n = new node(e);
			return;
		}

		if((*n)->info == e)
			return;

		else if((*n)->info > e)
			insert_util(&((*n)->left), e);

		else
			insert_util(&((*n)->right), e);
	}

	void insert(int e)
	{
		insert_util(&root, e);
	}

	bool search_util(node* n, int e)
	{
		if(n == NULL)
			return false;

		if(n->info == e)
			return true;

		if(n->info > e)
			return search_util(n->left, e);

		else
			return search_util(n->right, e);
	} 

	bool search(int e)
	{
		return search_util(root, e);
	}

	void inorder_util(node* n)
	{
		if(n != NULL)
		{
			inorder_util(n->left);
			cout << n->info << " ";
			inorder_util(n->right);
		}
	}

	void inorder()
	{
		inorder_util(root);
	}
};