#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
};

void print(Node* n)
{
	Node* last=n;
	cout<<"DLL :"<<endl;
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		last=n;
		n=n->next;
	}
	cout<<endl;
	cout<<"Reverse DLL:"<<endl;
	while(last!=NULL){
		cout<<last->data<<" ";
		last=last->prev;
	}
	cout<<endl;
}

void push(Node** head_ref,int data)
{
	Node* new_node= new Node();
	new_node->data=data;
	
	new_node->next=(*head_ref);
	new_node->prev=NULL;

	if((*head_ref)!=NULL)
		(*head_ref)->prev=new_node;
	
	(*head_ref)=new_node;	
}



void reverse(Node** head_ref){
	
	Node* curr_node=(*head_ref);
	Node* prev_node=NULL;
	
	while(curr_node!=NULL)
	{
		prev_node=curr_node->prev;
		curr_node->prev=curr_node->next;
		curr_node->next=prev_node;
		curr_node=curr_node->prev;
		
		
	}
	(*head_ref)=prev_node->prev;
}



int main(){
	
	Node* head=NULL;
	
	for(int i=10;i>0;i--)
		push(&head,i*10);
	
	reverse(&head);
	
	print(head);
	return 0;
}
