#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
//		Node(int val,Node* next):data(val),next(next){
//		}
		
		void printList(){
			Node* n=this;
			while(n!=NULL){
				cout<<n->data<<" ";
				n=n->next;
			}
		}
};



Node* merge(Node* a, Node* b,Node* tail,Node* dummy, Node* head3)
{

	while(1)
	{
		if(a ==NULL)
		{
			tail->next=b;
			break;
		}
		else if(b==NULL)
		{
			tail->next=a;
			break;
		}
		
		if(a->data <= b->data)
		{
			Node* new_node=new Node();
			dummy->next=new_node;
			tail->data=a->data;
			tail=tail->next; 
		}
		else
		{
			Node* new_node=new Node();
			dummy->next=new_node;
			tail->data=b->data;
			tail=tail->next; 	
		}
	}
	return head3;
	
}

void push(Node** head_ref,int data)
{
    Node* new_node = new Node(); 
    new_node->data = data;  
    new_node->next = (*head_ref);  
    (*head_ref) = new_node; 
}

int main(){
	Node* head1=NULL;
	
	for(int i=10;i>0;i--)
	{
		push(&head1,i*10);
	}
	
	head1->printList();
	
	Node* head2=NULL;
	for(int i=100;i>0;i=i-7)
	{
		push(&head2,i*10);
	}
	head2->printList();
	
	Node* dummy=new Node();
	Node* tail=dummy;
	Node* head3=dummy;
	
	merge(head1,head2,tail,dummy,head3);
	
	head3->printList();
	
}
