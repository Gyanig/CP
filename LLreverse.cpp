#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val,Node* next):data(val),next(next){}
		
		void printList(){
			Node* n=this;
			while(n!=NULL)
			{
				cout<<n->data<<" ";
				n=n->next;
			}
			cout<<endl;
		}
};


void push(Node** head_ref,int new_data)
{
	(*head_ref)=new Node(new_data,*head_ref);
}

void reverse(Node** head_ref,Node*& head){
	Node* prev_node=NULL,*curr_node=*head_ref,*next_node=NULL;
	
	while(curr_node!=NULL)
	{
		next_node=curr_node->next;
		curr_node->next=prev_node;
		prev_node=curr_node;
		curr_node=next_node;
	}
	head=prev_node;
}

Node* rrev(Node* head)
{
	if(head==NULL|| head->next==NULL)
		return head;
	
	Node* rest =rrev(head->next);
	head->next->next=head;
	head->next=NULL;
//	head->printList();
	return rest;	
}

void new_rec(Node* curr_node,Node* prev_node,Node** head);

void check(Node** head)
{
	if(!head)
		return;
	new_rec(*head,NULL,head);	
}

void new_rec(Node* curr_node,Node* prev_node, Node** head)
{
		if(!curr_node->next){
			*head=curr_node;
			curr_node->next=prev_node;
			return;
		}
		
		Node* next_node=curr_node->next;
		curr_node->next=prev_node;
		new_rec(next_node,curr_node,head);	
}

int main(){
	Node* head=NULL;
	for(int i=10;i>0;i--)
		push(&head,i*10);
	
	cout<<"LL"<<endl;
	head->printList();
	cout<<"First reverse method:"<<endl;
	reverse(&head,head);
	head->printList();
	
	cout<<"Recursive reverse method:"<<endl;
	head=rrev(head);
	head->printList();
	
	cout<<"Simple recursive method:"<<endl;
	check(&head);
	head->printList();
	
	return 0;
}
