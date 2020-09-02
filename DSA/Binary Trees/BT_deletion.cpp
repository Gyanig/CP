#include<bits/stdc++.h>
#include "binarytree.h"
#include "binarytree.cpp"
using namespace std;

void rightdeep(Node* root,Node* del);
Node* deletion(Node* root,int k)
{
	if(root==NULL)
		return NULL;
		
	if(root->left==NULL && root->right ==NULL)
	{
		if(root->data==k)
		{
			return NULL;
		}
		else
			return root;	
	}	
	
	
	queue <Node*>q;
	q.push(root);
	
	Node* n;
	Node* key_node=NULL;
	
	while(!q.empty())
	{
		n=q.front();
		q.pop();
		
		if(n->data==k)
			key_node=n;
			
		if(n->left)
			q.push(n->left);
		if(n->right)
			q.push(n->right);
	}
	
	if(key_node!=NULL)
	{
		int i=n->data;
		rightdeep(root,n);
		key_node->data=i;
	}
	
	return root;	
}

//using level order to find the last node
void rightdeep(Node* root,Node* d_node)
{
	
	queue <Node*> q;
	q.push(root);
	
	Node* n;
	while(!q.empty())
	{
		n=q.front();
		q.pop();
		
		if(n==d_node)
		{
			n=NULL;
			delete(d_node);
			return; 
		}
		
		if(n->right)
		{
			if(n->right==d_node)
			{
				n->right=NULL;
				delete(d_node);
				return;
			}
			else
				q.push(n->right);
		}
		
		if(n->left)
		{
			if(n->left==d_node)
			{
				n->left=NULL;
				delete(d_node);
				return;
			}
			else
				q.push(n->left);
		}
			
	}
}


int main()
{
	Node* root = new Node(10); 
    root->left = new Node(11); 
    root->left->left = new Node(7); 
    root->left->right = new Node(12); 
    root->right = new Node(9); 
    root->right->left = new Node(15); 
    root->right->right = new Node(8); 
  
    cout << "Inorder traversal before deletion : "; 
    print_inorder(root); 
  
    int key = 11; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    print_inorder(root); 
    
	return 0;
}
