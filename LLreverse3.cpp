#include<bits/stdc++.h>
using namespace std;
typedef uintptr_t ut;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data)
		{
			this->data=data;
			next=NULL;
		}
};

class LinkedList{
	public:
		Node* head;
		LinkedList(){
			head=NULL;
		}
		
		void print(){
			Node*temp= head;
			while(head!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		
		void push(int data){
			Node* tmp= new Node(data);
			tmp->next=head;
			head=tmp;
		}
		void reverse()
		{
			Node* prev_node=NULL;
			Node* curr_node=head;
			while(curr_node!=NULL)
			{
				curr_node=(Node*)((ut)prev_node ^ (ut)curr_node ^ (ut)(curr_node->next) ^ (ut)(curr_node->next = prev_node) ^ (ut)(prev_node = curr_node));
			}
			head=prev_node;
		}
};


int main(){
	LinkedList ll;
	for(int i=10;i>0;i--)
		ll.push(i*10);
	
	ll.print();
	
	ll.reverse();
	ll.print();
	
	return 0;
}


