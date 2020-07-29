#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val,Node* next):data(val),next(next){
		}
		
		void printList(){
			Node* n=this;
			while(n!=NULL){
				cout<<n->data<<" ";
				n=n->next;
			}
		}
};



Node* merge(Node* a, Node* b)
{
	Node dummy;
	Node* tail=&dummy;
	dummy.next=NULL;
	
	
}

void push(Node** head_ref,int data)
{
	(*head_ref)=new Node(data,*head_ref);
}

int main(){
	Node* head=NULL;
	
	for(int i=10;i>0;i--)
	{
		push(&head,i*10);
	}
	
	head->printList();
	
}
