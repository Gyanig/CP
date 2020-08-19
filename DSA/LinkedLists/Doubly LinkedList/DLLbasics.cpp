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

void insertafter(Node* prev_node,int data)
{
	Node* new_node= new Node();
	new_node->data=data;
	
	Node* next_node=prev_node->next;
	new_node->next=next_node;
	new_node->prev=prev_node;
	prev_node->next=new_node;
	next_node->prev=new_node;

}

void insertbefore(Node** head_ref, Node* next_node,int data)
{
	Node* new_node= new Node();
	new_node->data=data;
	
	Node* prev_node=next_node->prev;
	new_node->next=next_node;
	new_node->prev=prev_node;
	prev_node->next=new_node;
	next_node->prev=new_node;
	
}

void append(Node** head_ref,int data){
	Node* new_node= new Node();
	new_node->data=data;
	
	Node* last=(*head_ref);

	if ((*head_ref) == NULL) { 
        new_node->prev = NULL; 
        (*head_ref)= new_node; 
        return; 
    }
	
	while(last->next!=NULL){
		last=last->next;
	}
	
	new_node->prev=last;
	last->next=new_node;
	new_node->next=NULL;
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
	
	
	insertafter((head->next->next),35);
	append(&head,110);
	insertbefore(&head,(head->next->next->next->next->next),55);
	
	print(head);
		
	del(&head,head->next->next);
	
	print(head);
	
	reverse(&head);
	
	print(head);
	return 0;
}
