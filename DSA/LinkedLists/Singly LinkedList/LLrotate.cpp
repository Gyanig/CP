#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void print(Node* n)
{
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}

void push(Node** head_ref,int data)
{
	Node* new_node= new Node();
	new_node->data=data;
	new_node->next=*head_ref;
	(*head_ref)=new_node;
}

void rotate(Node** head_ref,int key){
	
	int k1=key;
	Node* head=(*head_ref);
	Node* prev_node=head;
	k1--;
	while(k1--){
		prev_node=prev_node->next;
	}
	
	Node* n= prev_node->next;
	Node* new_head=n;
	cout<<n->data<<" "<<prev_node->data<<" "<<new_head->data<<endl;
	
	while(n->next!=NULL){
		n=n->next;
	}
	cout<< n->data<<" "<<head->data<<endl;
	n->next=head;
	prev_node->next=NULL;
	(*head_ref)=new_head;
}

int main(){

	Node* head=NULL;
	
	for(int i=10;i>0;i--)
		push(&head,i*10);
	
	print(head);	
	cout<<"Enter key to rotate LL:"<<endl;
	int k;
	cin>>k;
	
	rotate(&head,k);
	print(head);
}
