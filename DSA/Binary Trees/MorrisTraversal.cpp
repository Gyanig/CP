#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int val)
	{
		data=val;
		left= NULL;
		right= NULL	;
	}
};

//without stack and recursion 
// we are going to use linkers as in threaded binary

void inorder(Node* temp)
{
	Node* curr=temp;
	Node* pre;

	if(temp==NULL) return;

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
				curr=curr->left;
			}
			else
			{
				pre->right=NULL;
				cout<<curr->data<<" ";
				curr=curr->right;
			}	
		}
	}
}


int main()
{
	Node* root = new Node(10);
    root->left =  new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right =  new Node(8);

	inorder(root);
	return 0;
}

