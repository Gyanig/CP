// creating tree structure

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* create_node(int d){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=d;
	new_node->left=NULL;
	new_node->right=NULL;
	
	return new_node;
}

int main()
{	
	struct Node* root=create_node(1);
	root->left=create_node(2);
	root->right=create_node(3);
	root->left->left=create_node(4);
	
	/*
	        1 
	     /     \ 
	    2       3 
	   / \     / \ 
	  4 NULL NULL NULL 
	 / \ 
  NULL NULL 
	*/
	
	getchar();
	return 0;
}
