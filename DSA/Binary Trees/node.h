#ifndef NODE_H
#define NODE_H

#include<cstddef>

class SNode{
	public:
		int data;
		SNode* next;
	
		SNode(int d)
		{
			data=d;
			next=NULL;
		}
};

class Node2{
	public:
		int data;
		DNode* prev;
		DNode* next;
		
		DNode(int d)
		{
			data=d;
			prev=NULL;
			next=NULL;
		}
};

class TNode{
	public:
		int data;
		TNode* left;
		TNode* right;
		
		TNode(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};


#endif
