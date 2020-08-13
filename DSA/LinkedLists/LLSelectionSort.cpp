#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};

class LinkedList{
	public:
		Node* head;
		
		LinkedList(int data){
			head=NULL;
		}
	
};

void sort(int l){ //l is length
	Node *p, *q;
	p=head;
	for(int i=0;i<l;i++){
		q=p->next;
		for(int j=i+1;j<l;j++){
			if(p->data>q->data){
				int temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
	}
	
}


int main(){
	
}
