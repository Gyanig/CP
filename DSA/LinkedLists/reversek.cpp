#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void push(Node** head_ref, int data){
	Node* new_node= new Node();
	new_node->data=data;
	new_node->next=*head_ref;
	(*head_ref)=new_node;
}

void print(Node* n){
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}

void reverse(Node** head_ref,int k)
{
	Node* head=*head_ref;
	Node* curr=head;
	Node* prev=NULL;
	Node* next=NULL;
	while(k--)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	(*head_ref)->next=curr;
	(*head_ref)=prev;
}


int main(){
	Node* head=NULL;
	
	for(int i=10;i>0;i--)
		push(&head,i*10);

	print(head);
	int k=15;
	k=k%10;
	reverse(&head,k);
	print(head);
	return 0;
}
