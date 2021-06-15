#include<bits/stdc++.h>
using namespace std;

struct TNode{
	int data;
	TNode* left;
	TNode* right;
	bool rightThread;
	
	TNode(int val)
	{
		data=val;
		left= NULL;
		right= NULL	;
		rightThread= false;
	}
};


void ThreadedTreeCreation(TNode* temp)
{
	// this is the exact implementation of Morris traversal

	// we use the loop to create threads between TNodes requried 
	// we also run a loop to print the required TNodes
	// included the bool values  
	TNode* curr=temp;
	TNode* pre;
	if(curr==NULL) return ;
	while(curr!=NULL)
	{
		if(curr->left == NULL)
		{
			cout<<curr->data<<" ";
			curr= curr->right;
		}
		else
		{
			pre=curr->left;
			while(pre->right!=NULL && pre->right!=curr)
				pre=curr->right;

			if(pre->right==NULL)
			{
				pre->right=curr;
				pre->rightThread=true;
				curr=curr->left;
			}
			else
			{
				pre->right=NULL;
				cout<<curr->data<<" ";
				curr->rightThread=true;
				curr=curr->right;
			}	
		}
	}
}

TNode* leftmost(TNode* n)
{
	if(n==NULL) return NULL;
	// find the leftmost TTNode 
	while(n->left!=NULL)
		n=n->left;
	return n;
}

void inordertrav(TNode* temp)
{
	TNode* curr= leftmost(temp);
	while(curr!=NULL){
		cout<<curr->data<<""<<endl;
		if(curr->rightThread)
			curr=curr->right;
		else
			curr=leftmost(curr->right);	
	}
}


int main()
{
	TNode* root = new TNode(10);
    root->left =  new TNode(11);
    root->left->left = new TNode(7);
	// root->left->right = new TNode(12);
    root->right = new TNode(9);
    root->right->left = new TNode(15);
    root->right->right =  new TNode(8);
	ThreadedTreeCreation(root);
	cout<<endl;
	inordertrav(root);
	return 0;
}