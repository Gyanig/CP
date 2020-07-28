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
			while(n!=NULL)
			{
				cout<< n->data<<" ";
				n=n->next;
			}
			cout<<"\n";
		}
};

Node* merge(Node* a, Node* b); 
void Frontbacksplit(Node* source, Node** front_Ref, Node** back_Ref);

void push(Node** head_ref,int data)
{
	(*head_ref)=new Node(data,*head_ref);
}

void mergesort(Node** head_ref){
	Node* head=*head_ref;
	Node* a;
	Node* b;
	
	if((head==NULL) || (head->next==NULL)){
		return;
	}
	
	Frontbacksplit(head,&a,&b);
	mergesort(&a);
	mergesort(&b);
	
	*head_ref=merge(a,b);
}

//uses slow and fast pointer technique as slow reachs mid, when fast reachs end

void Frontbacksplit(Node* source, Node** front_ref,Node** back_ref){
	Node*fast,*slow;
	slow=source;
	fast=source->next;
	
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL)
		{
			fast=fast->next;
			slow=slow->next;
		}
	}
	*front_ref=source;
	*back_ref=slow->next;
	slow->next=NULL;
//	(*front_ref)->printList();
//	(*back_ref)->printList();
}

Node* merge(Node* a,Node* b){	
	Node* r=NULL;
	if(a==NULL)
		return(b);
	else if(b==NULL)	
		return (a);
		
	if(a->data <= b->data)
	{
		r=a;
		r->next=merge(a->next,b);
	}
	else {
		r=b;
		r->next=merge(a,b->next);
	}
	return r;			
}

int main(){
	Node* res = NULL; 
    Node* a = NULL; 

    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
  
  	a->printList();
    /* Sort the above created Linked List */
    mergesort(&a); 
  
    cout << "Sorted Linked List is: \n"; 
    a->printList(); 
 	
	return 0;
}
