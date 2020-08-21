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

<<<<<<< HEAD
Node* partition()

=======
>>>>>>> 8be0242... DSA folder update

int main(){
	Node* head=NULL;
	for(int i=10;i>=1;i--)
		push(&head,i*10);
		
	print(head);

<<<<<<< HEAD
	cout<<"\nEnter 10 elements to LL :\n";
	Node* n=head;
	for(int i=0;i<10;i++) // we can use count to change values of all nodes
	{
		int inp=0;
		cin<<inp;
		(n)->data=inp;
		(n)=(n)->next;
	}
	
	
	quicksort()
=======
>>>>>>> 8be0242... DSA folder update
	return 0;
}

