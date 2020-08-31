#include<bits/stdc++.h>
using namespace std;

// three traversals -
//	In Order
//	Pre Order
//	Post Order

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


int main()
{
	Node* root= new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->right->left=new Node(60);
	root->left->right->right=new Node(70);

	
	cout<<"In Order traversal! "<<endl;
	print_inorder(root);
	cout<<endl<<endl;
	
	cout<<"Pre Order traversal!"<<endl;
	print_preorder(root);
	cout<<endl<<endl;
	
	cout<<"Post Order traversal!"<<endl;
	print_postorder(root);
	cout<<endl;		
	return 0;
}
