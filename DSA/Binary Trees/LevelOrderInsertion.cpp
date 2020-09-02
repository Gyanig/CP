#include<iostream>
//#include<algorithms>
#include<queue>
#include "binarytree.h"
#include "binarytree.cpp"

using namespace std;
// in order insertion  
// since using a level order traversal method we take a queue in consideration
//  we insert the input at the first posible possible postion

void inorderinsert(Node* root,int input)
{
	if(root==NULL)
	{
		cout<<"Tree is empty! root is ur insertion";
		root->data=input;
		return;
	}
	
	queue <Node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node* n=q.front();
//		cout<<n->data<<" ";
		q.pop();
		
		if(!n->left)
		{
			n->left=new Node(input);
			break;
		}
		else
			q.push(n->left);
	
		if(!n->right)
		{
			n->right=new Node(input);
			break;
		}
		else
			q.push(n->right);
	}
}


int main()
{
	
	Node* root= new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->right->left=new Node(60);
	root->left->right->right=new Node(70);
	
	cout<<"Enter a data to insert inorder : ";
	int input;
	cin>>input;
	
	inorderinsert(root,input);
	
	bft_queue(root);
	
	return 0;
}
