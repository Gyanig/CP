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

int main(){
	//input 1
	Node* head1=NULL;
	cout<<" enter a number "<<endl;
	unsigned long long int n,np;
	cin>>n;
	np=n;
	while(np!=0){
		int d=np%10;
		push(&head1,d);
		np/=10;
	} 
	print(head1);
	
	//input 2
	Node* head2=NULL;
	cout<<" enter another number "<<endl;
	unsigned long long int m,mp;
	cin>>m;
	mp=m;
	while(mp!=0){
		int d=mp%10;
		push(&head2,d);
		mp/=10;
	} 
	print(head2);
	
	
	//output the sum
	Node* final=NULL;
	unsigned long long int o,op;
	o=n+m;
	cout<<o<<endl;
	op=o;
	while(op!=0){
		int d=op%10;
		push(&final,d);
		op/=10;
	}
	print(final);

}
