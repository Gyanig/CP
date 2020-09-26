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

void del(Node** head_ref,Node* del)
{
	if((*head_ref)==NULL || del==NULL)
		return;
		
	if(*head_ref==del)
		(*head_ref)=del->next;
	
	if(del->next!=NULL)
		del->next->prev=del->prev;
	
	if(del->prev!=NULL)
		del->prev->next=del->next;
		
	free(del);
	return;				
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


int main(){
	
	Node* head=NULL;
	
	for(int i=10;i>0;i--)
		push(&head,i*10);

	print(head);
	
	del(&head,head->next->next);
		
	print(head);
	return 0;
}
