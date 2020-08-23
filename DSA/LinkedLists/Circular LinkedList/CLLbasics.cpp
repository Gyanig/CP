#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

//we can use counting nodes for tracking the number of nodes in the CLL
//we use the concept of slow and fast pointer to do the above
//Not approaching the above as I just have to keep track of the last node which makes the loop


//using the just the tail node to do any operation
Node* addempty(Node* tail,int input)
{

	if(tail!=NULL)
		return tail;

		
	Node* new_node=new Node();
	new_node->data=input;
	tail=new_node;
	tail->next=tail;
	return tail;
}

Node* push(Node* tail,int input)
{
//	print(tail);
	
	if(tail==NULL)
		return addempty(tail,input);
		
	Node* new_node=new Node();
	new_node->data=input;
	new_node->next=tail->next;
	tail->next=new_node;
	
	return tail;	
}


Node* append(Node* tail,int input)
{
//	print(tail);
	
	if(tail==NULL)
		return addempty(tail,input);
	
	Node* new_node=new Node();
	new_node->data=input;
	new_node->next=tail->next;
	tail->next=new_node;
	tail=new_node;
		
	return tail;	
}


Node* addafter(Node* tail,int input,int find)
{
//	print(tail);
	
	if(tail==NULL)
		return NULL;
	
	Node* p=NULL;
	p=tail->next;
	Node* new_node=new Node();
	
	do
	{
		if((p->data)==find)
		{
			new_node->data=input;
			new_node->next=p->next;
			p->next=new_node;	
			
			if(p==tail)
				tail=new_node;
			return tail;
		}	
		p=p->next;	
	}while(p!=(tail->next));
	
	cout<<find<<"Not present"<<endl;
	return tail;	
}


void print(Node* tail)
{
	Node* p;
	
	if(tail==NULL)
	{
		cout<<"Empty list"<<endl;	
		return;
	}
	
	p=tail->next;
	
	do{
		cout<<(p->data)<<" ";
		p=p->next;
		
	}while(p!=(tail->next));
	cout<<endl;
}

//	Using few extra methond to count the number node in the CLL
//  Using fast and slow pointer method also to detect loop

int count(Node* tail)
{
	Node* n=tail->next;
	int count=1;
	do
	{
		count++;
		n=n->next;
	}while(n!=tail);
	
	return count;
}


int main()
{
	Node* tail=NULL;
	
	tail=addempty(tail,5);
	tail=push(tail,6);
	tail=push(tail,8);
	tail=append(tail,10);
	tail=append(tail,11);
	tail=addafter(tail,9,8);
	
	int c=count(tail);
	cout<<"Count of the node: "<<c<<endl;
	
	print(tail);
	return 0;
}
