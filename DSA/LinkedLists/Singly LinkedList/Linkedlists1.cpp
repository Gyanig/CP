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
	
	node** head_ref=&head;
	cout<<*head_ref<<" "<<(&((*head_ref)->next->data))<<endl;
	
	printlist(head);
	
}
