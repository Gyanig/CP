//Using the binary search tree, also study balanced tree structures and rotation

#include<bits/stdc++.h>
#include<queue>

using namespace std;

class BST{
	public:
		int data;
		BST* left;
		BST* right;
		
		BST();
		
		BST(int);
		
		BST* insert(BST* , int);
		
		void inorder(BST*);
	
};

BST::BST():data(0),left(NULL),right(NULL){}

BST::BST(int d)
{
	data=d;
	left=NULL;
	right=NULL;
}

BST* BST::insert(BST* root,int d)
{
	if(!root)
	{
		return new BST(d);
	}
	
	if(d>root->data)
	{
		root->right= insert(root->right,d);
	}
	else
	{
		root->left= insert(root->left,d);
	}
	return root;
}

void BST::inorder(BST* root)
{
	if(!root)
	{
		return;
	}
		
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
}

int main()
{
	BST b, *root = NULL; 
	
    root = b.insert(root, 50); 
	b.insert(root, 30); 
    b.insert(root, 20); 
    b.insert(root, 40); 
    b.insert(root, 70); 
    b.insert(root, 60); 
    b.insert(root, 80); 
  	b.insert(root, 20);
  	
    b.inorder(root);
    
	return 0;
}

