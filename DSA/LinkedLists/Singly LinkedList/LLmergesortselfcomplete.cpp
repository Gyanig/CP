#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node*next;
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

void Spilt(Node* source, Node** front_ref,Node** back_ref)
{
	Node* slow;
	Node* fast;
	slow=source;
	fast=source->next;
	
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	
	*front_ref=source;
	*back_ref=slow->next;
	slow->next=NULL;
	
}

Node* merge(Node* a, Node*b){
	Node* result =NULL;
	
	if(a==NULL)
		return (b);
	else if(b==NULL)
		return (a);	
		
	if(a->data <= b->data){
		result= a;
		result->next=merge(a->next,b);
	}
	else{
		result= b;
		result->next=merge(b->next,a);
	}
	
	return result;
}

void mergesort(Node** head_ref){
	Node* head= *head_ref;
	Node* a;
	Node* b;
	
	if(head==NULL || head->next==NULL) //length is 0 or 1 or LL
	{
		return;
	}
	
	Spilt(head,&a,&b); // using slow fast pointer to divide the array into two parts recursively
	
	mergesort(&a);
	mergesort(&b);
	
	(*head_ref)=merge(a,b);
	
}


int main(){

    Node* a = NULL; 
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
	
	cout << "Un-Sorted Linked List is: \n"; 
	print(a);
  	
    mergesort(&a); 
  
    cout << "Sorted Linked List is: \n"; 
    print(a); 
    
	return 0;
}
