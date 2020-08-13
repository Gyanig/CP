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

void detectloop(Node** head_ref)
{
	Node* head=* head_ref;
	Node* slow;
	Node* fast;
	slow=head;
	fast=head->next;
	bool flag=false;
	int c=0; //counter for number of time slow moves forward, 
			//coz it has to move forward same amount to reach loop meet
	while(fast!=slow && flag==false)
	{
		c++;
		fast=fast->next;
		if(fast!=slow)
		{
			slow=slow->next;
			fast=fast->next;
		}
		if(fast==slow)
		{
			cout<<(fast->data)<<" "<<(slow->data)<<endl;
			flag=true;
			break;
		}
	}
	
	if(flag==true)
		cout<<"LOop deCtected "<<c<<" counter"<<endl;
	else if(flag== false)
		cout<<"Goodnight "<<c<<" counter"<<endl;

	//counting number of nodes in loop
	Node* m=slow;
	m=m->next;
	int k=0;
	while(m!=slow){
		k++;
		m=m->next;
	}
	k++;
	cout<<k<<endl;
	
	//finding looping point
	Node* h1=head;
	Node* h2=head;
	while(k--){
		h2=h2->next;
	}
	
	while(h1!=h2){
		h1=h1->next;
		h2=h2->next;
	}
	cout<<h1->data<<" "<<h2->data<<endl;
	
	//removing loop
	Node* tail=h1;
	while((tail->next)!=h2)
	{
		tail=tail->next;
	}
	tail->next=NULL;
	
}

Node* newNode(int key) 
{ 
    Node* temp = new Node(); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 


int main(){
//	Node* head=NULL;
	
	Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10);
	head->next->next->next->next->next = newNode(22);
    head->next->next->next->next->next->next = newNode(1);

	print(head);
	
    head->next->next->next->next->next->next->next = head->next->next;
    
	detectloop(&head);
	cout<<"Removed the loop"<<endl;
	print(head);
	return 0;
}
