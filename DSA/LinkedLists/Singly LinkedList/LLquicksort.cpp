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


//find the end node - pivot
// using first node starting 
// write partiton 
// quicksort recusion returns head ref
Node* tail_node(Node* cur)
{
	while(cur!=NULL && cur->next!=NULL)
	{
		cur=cur->next;
	}
	return cur;
}

Node* partition(Node* head,Node*end,Node**i, Node**j)
{
	//setting thepivot to end
	Node* pivot =end;
	Node* prev=NULL;
	//taking new head and tail
	Node* cur=head;
	Node* tail=pivot;
	
	while(cur!=pivot)
	{
		print(head);
		if(cur->data < pivot->data) // changing sign to > makes it descending
		{
			if((*i)==NULL)
				(*i)=cur;
			prev=cur;
			cur=cur->next;
		}
		else
		{
			if(prev)
				prev->next=cur->next;
			
			//swap nodes
			Node* tmp=cur->next;
			cur->next=NULL;
			tail->next=cur;
			tail=cur;
			cur=tmp;	
		}	
	}
	if((*i)==NULL)
	{
		(*i)=pivot;
	}
	
	*j=tail;
	
	return pivot;
}

Node* quicksort_recursion(Node* head, Node* end)
{
	//base condition lb<ub
	if(!head || head==end)
		return head;
	
	Node* i=NULL;	
	Node* j=NULL;
	
	//finding pivot best position using partition
	Node* pivot=partition(head,end,&i,&j);
	
	//call tail recusion
	if(i != pivot)
	{
		//setting the node before the pivot node NULL
		Node* tmp=i;
		while(tmp->next != pivot)
		{
			tmp=tmp->next;
		}
		tmp->next=NULL;
		
		//sorting the left side
		i=quicksort_recursion(i,tmp);
		
		tmp=tail_node(i);
		tmp->next=pivot;
	}
	 	
	//sorting the right side 
	pivot->next=quicksort_recursion(pivot->next,j);
	return i;
}


void quicksort(Node** head_ref)
{
	(*head_ref)=quicksort_recursion((*head_ref),tail_node(*head_ref));
	return;
}

int main(){
	Node* head=NULL;
	for(int i=10;i>=1;i--)
		push(&head,i*10);
		
	print(head);

	cout<<"\nEnter 10 elements to LL :\n";
	Node* n=head;
	for(int i=0;i<10;i++) // we can use count to change values of all nodes
	{
		int inp=0;
		cin>>inp;
		(n)->data=inp;
		(n)=(n)->next;
	}
	
	print(head);
	
	quicksort(&head);
	
	print(head);
	return 0;
}

