#include<bits/stdc++.h>
using namespace std;


class Node{
	int nc;
	public:
		Node* root;
		int data;
		Node* left;
		Node* right;
		
		createNode(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
			nc++;
		}
		
		// write a menu driven program for this 
		void insertleft(Node* l,int d);
		void insertright(Node* r,int d);
		void deletenode(int d);
		void deletepos(Node* link);
		Node* find(int d);
		Node* find_parent(int d);
		
};

// operations to be done : insert left node, insert right node, delete left sub-tree , 
//							delete right sub-tree, display the tree- depends on the traversal 
//							maybe the whole or at particular position only,
//							find particular node if exists of not, find parent 					 
//							

void Node::insertleft(Node* l,int d){
	Node* new_node= createNode(d);
	l->left=new_node;
}

void Node::insertright(Node* r,int d){
	Node* new_node= createNode(d);
	r->right=new_node;
}

void Node::deletenode(int d){
	find()
	
}

void Node::deletepos(Node* link){
	
	link->left=NULL;
	link->right=NULL;
}

Node* Node::find(int d){
	Node* n=root;
	while()
	
}

Node* Node::find_parent(int d){
	
	
}

int main()
{
	
	
	
	return 0;
}
