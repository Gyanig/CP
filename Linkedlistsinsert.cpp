#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node*next;
		
		void display(node* n){
			cout<<n->data<<"\n";	
		}	
};

void printlist(node* n)
{
	
	while(n != NULL)
	{
//		cout<<n->data<<endl;
		n->display(n);
		n=n->next;
	}
}

void push(node**head_ref,int new_data)
{
	node* new_head= new node();
	new_head->data= new_data;
	new_head->next= (*head_ref);
	(*head_ref)=new_head;
}

void Insertafter(node* prev_node,int new_data)
{
	if(prev_node==NULL)
	{
		cout<<"NULL node referred";
		return;
	}
	
	node* new_node= new node();
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
}

void append(node* tail,int new_data)
{
	// This append works, but geeks for geeks shows different 
	while((tail->next) != NULL)
	{
		tail=tail->next;
	}
	node* new_tail=new node();
	new_tail->data=new_data;
	tail->next=new_tail;
	new_tail->next=NULL;
}

int main(){
	node* head= NULL; 
	node* second=NULL;
	node* third=NULL;
	
	head	= new node();
	second	= new node();
	third 	= new node();
	
	cout<<head <<" "<< second <<" "<<third <<endl;
	
	head->data = 10;
	head->next = second;
	
	second->data = 20;
	second->next = third;
	
	third->data = 30;
	third->next = NULL;
	
	cout<<head->data <<" "<< second->data <<" "<<third->data <<endl;
	cout<<head->next <<" "<< second->next <<" "<<third->next <<endl;
	
	//Inserting before head node
	
//	node* new_head=NULL;
//	new_head = new node();
//	new_head->data=5;
//	new_head->next= head;

	push(&head,5);

//	cout<<&head<<endl ;
	
	//Inserting after a given node
//	
//	node* new_node=NULL;
//	new_node=new node();
//	new_node->data=25;
//	second->next=new_node;
//	new_node->next=third;
	
	Insertafter(head->next->next,25); //memory location of previous node
	
	//Inserting at last
	
//	node* new_tail=new node();
//	new_tail->data=35;
//	third->next=new_tail;
//	new_tail->next=NULL;

	append(head,40);
		
	printlist(head);
	
	
}
