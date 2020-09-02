#include<bits/stdc++.h>
#include "binarytree.h" 

using namespace std;

// better solution at it is O(n) complexity-space and time

void bft_queue(Node* root)
{
	queue <Node *> q;
	
	//base condition
	if(root==NULL)
	{
		cout<<"Tree is empty!"<<endl;
		return;
	}
	
	q.push(root);
	
	while(q.empty()==false)
	{
		Node* n=q.front();
		cout<<n->data<<" ";
		q.pop();
		
		if(n->left!=NULL)
		{
			q.push(n->left);
		}
		if(n->right!=NULL)
		{
			q.push(n->right);
		}
	}
}


void print_inorder(Node* n)
{
	if(n==NULL)
		return;
		
//	(left,root,right)	
	print_inorder(n->left);
	cout<<n->data<<" ";
	print_inorder(n->right);	
	
}

void print_preorder(Node* n)
{
	if(n==NULL)
		return;
		
//	(root,left,right)
	cout<<n->data<<" ";	
	print_preorder(n->left);
	print_preorder(n->right);	
	
}

void print_postorder(Node* n)
{
	if(n==NULL)
		return;
		
//	(left,right,root)
	print_postorder(n->left);
	print_postorder(n->right);	
	cout<<n->data<<" ";	
	
}

