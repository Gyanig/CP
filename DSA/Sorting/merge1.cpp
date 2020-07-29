#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val,Node* next):data(val),next(next){
		}
		
		void print(){
			Node* n=this;
			while(n!=NULL)
			{
				cout<<n->data<<" ";
				n=n->next;
			}
			cout<< endl;
		}
};

void push(Node** head_ref,int data){
	(*head_ref)=new Node(data,*head_ref);
}

void merge(Node*& h1,Node*& h2)
{
	if(h1==NULL || h2==NULL)
		return;
		
	while(h1!=NULL || h2!=NULL)	
	{
		int d1=(h1->data);
		int d2=(h2->data);
//		cout<<d1<<" "<<d2<<"\n";
		
		if(d1>d2)
		{
			
			while(((h1->next->data)<(h2->data))&&(h1->next!=NULL))
			{
				h1=h1->next;
			}
			Node* tmp2=h2->next;
			h2->next=h1;
			h1=h2;
			h2=tmp2;
		}
		else if(d1<d2)
		{
			while((h1->next!=NULL)&&((h1->next->data)<(h2->data)))
			{
				h1=h1->next;
			}
			if(h1->next==NULL)
			{
				h1->next=h2;
				
				return;
			}
			Node* tmp1=h1->next;
			h1->next=h2;
			Node* tmp2=h2->next;
			h2->next=tmp1;
			h2=tmp2;
		}
		else
		{
			h1=h1->next;
			h2=h2->next;
		}
//		(*head)->print();
	}
	
	return;
}


int main(){
	Node* head1=NULL;
	
	for(int i=10;i>0;i--)
		push(&head1,i*10);

	
	head1->print();
	
	Node* head2=NULL;
	
	for(int i=102;i>=5;i-=5)
		push(&head2,i);
		
	head2->print();
	
	//let's always merge with the first LL
	Node* head=head1;
	merge(head1,head2);
	head->print();	
}


