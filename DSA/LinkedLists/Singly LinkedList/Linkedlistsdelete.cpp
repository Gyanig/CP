#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void push(Node** head_ref,int new_data)
{
	Node* new_node=new Node();
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}

void append(Node** head_ref,int new_data)
{
	Node* new_node=new Node();
	Node* last= *head_ref;
	new_node->data=new_data;
	new_node->next=NULL;
	
	if(head_ref==NULL)
	{
		*head_ref=new_node;
	}
	
	while(last->next != NULL)
	{
		last=last->next;
	}
	last->next=new_node;
	
}

void insertafter(Node* prev_node,int new_data)
{
	if(prev_node==NULL)
		return;
		
	Node* new_node=new Node();
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
	
}

void delete_node(Node** head_ref,int key)
{
	Node* temp=*head_ref,*prev;
	if(temp!=NULL && temp->data==key)
	{
		*head_ref=temp->next;
		delete temp;
		return;
	}
	
	while(temp!=NULL && temp->data !=key )
	{
		prev=temp;
		temp=temp->next;
	}
	
	if(temp==NULL)
		return;
		
	prev->next=temp->next;
	delete temp;	
	
}

void delete_pos(Node** head_ref,int pos)
{
	if(*head_ref==NULL)
		return;
	
	Node* temp=*head_ref;
	
	if(pos==0)
	{
		*head_ref=temp->next;
		delete temp;
		return;
	}
	
	int i=0;
	while(temp->next!=NULL && i<pos-1){
		temp=temp->next;
		i++;
	}
	
	if(temp==NULL || temp->next==NULL)
		return;
		
	temp->next=temp->next->next;	
	delete temp;
	
}


void printlist(Node* node)
{
	while(node!=NULL)
	{
		cout<<node->data<<" ";
		node=node->next;
	}
	
}

int length(Node* node) // itertive way
{
	int count=1;
	while(node->next!=NULL)
	{
		count++;
		node=node->next;
	}
	return count;
}


int get_count(Node* head)
{
	if(head==NULL)
		return 0;
		
	return 1+get_count(head->next);	
}

int main()
{
	Node* head= NULL;
	push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
    append(&head,10);
    
	cout<<"Created Linked List: "<<endl; 
    printlist(head); 
    delete_node(&head, 1); 
    
    cout<<"\nLinked List after Deletion of 1: "<<endl; 
    printlist(head); 
    cout<<"\nLinked List after Deletion at position 2: "<<endl;
	delete_pos(&head,2);
	printlist(head);
	
	int l=length(head);
	int lr=get_count(head);
	cout<<"\nLength of the LL :"<<l<<" recursively :"<<lr<<endl;
	
	
}
