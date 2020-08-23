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

Node* Spilt(Node* head)
{
	Node* slow=head;
	Node* fast=head;
	
	while(fast->next && fast->next->next)
	{
		slow=slow->next;
		fast=fast->next->next;	
	}
	Node* tmp= slow->next;
	slow->next=NULL;
	return tmp;
	
}

Node* merge(Node* a, Node*b){
	Node* result =NULL;
	
	if(a==NULL)
		return (b);
	else if(b==NULL)
		return (a);	
		
	if(a->data < b->data){
		a->next=merge(a->next,b);
		a->next->prev=a;
		a->prev=NULL;
		return a;
	}
	else{
		b->next=merge(b->next,a);
		b->next->prev=b;
		b->prev=NULL;
		return b;
	}
}

Node* mergesort(Node* head){
	
	if(head==NULL || head->next==NULL) //length is 0 or 1 or LL
	{
		return head;
	}
	
	Node* b=Spilt(head); // using slow fast pointer to divide the array into two parts recursively
	
	head=mergesort(head);
	b=mergesort(b);
	
	return merge(head,b);
	
}


int main(){
	
	Node* head=NULL;
	
	cout<<"Enter 10 data elements tp sort"<<endl;
	int data;
	for(int i=10;i>0;i--)
	{
		cin>>data;
		push(&head,data);
	}
		
	cout<<"Without sorting"<<endl;
	print(head);
	cout<<"After Sorting"<<endl;
	head=mergesort(head);
	print(head);
	return 0;
}
