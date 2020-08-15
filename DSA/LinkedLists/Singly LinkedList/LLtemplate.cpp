#include<bits/stdc++.h>
using namespace std;

class Node{
	public:	
		int data;
		Node* next;
		
		Node(int data){
			this->data=data;
			next=NULL;
		}
};

class LinkedList{
	public:	
		Node* head;
		
		LinkedList()
		{
			head=NULL;
		}
		
		void print(){
			Node* n=head;
			while(n!=NULL){
				cout<<n->data<<" ";
				n=n->next;
			}
			cout<<endl;
		}
		
		//insertion
		void push(int data){
			Node* new_node=new Node(data);
			new_node->next=head;
			head=new_node;
		}
		
		void append(Node** head_ref,int data){
			Node* new_node=new Node(data);
			Node *tail=*head_ref;
			while(tail->next!=NULL){
				tail=tail->next;
			}
			tail->next=new_node;
		}
		
		void insertafter(Node* prev_link,int data)
		{
			Node* new_node=new Node(data);
			new_node->next=prev_link->next;
			prev_link->next=new_node;
		}
		
		
		//reverse- recursive
		Node* rrev(Node* head){
			if(head==NULL|head->next==NULL){
				return head;
			}
			
			Node* rest=rrev(head->next);
			head->next->next=head;
			head->next=NULL;
			return rest;
		}
		
};



int main(){
	LinkedList LL1;
	LL1.push(3);
	LL1.append(&LL1.head,8);
	LL1.append(&LL1.head,10);
	
	LinkedList LL2;
	LL2.push(5);
	LL2.append(&LL2.head,6);
	LL2.append(&LL2.head,12);
	
	LL1.print();
	LL2.print();
	
	return 0;
}
