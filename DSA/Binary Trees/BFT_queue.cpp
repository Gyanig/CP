#include<bits/stdc++.h>
using namespace std;

// better solution at it is O(n) complexity-space and time

class  Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int d)
		{
			data=d;
			left=right=NULL;
		}
};

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



int main()
{
	Node* root= new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->right->left=new Node(60);
	root->left->right->right=new Node(70);
	
	bft_queue(root);
	
	return 0;
}
