#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void push(Node** head_ref,int new_data)
{
	Node* new_node=new Node();
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;	
}
int get_count(Node* c);

// interesting way of swapping :using one loop (optimized)
void just_swap(Node *&a,Node *&b)
{
	Node* tmp= a;
	a=b;
	b=tmp;
	delete tmp;
}

void new_swap(Node** head_ref,int x,int y)
{
	if(x==y)return;
	
	Node** a=NULL,**b=NULL;
	
	while(*head_ref)
	{
		if((*head_ref)->data==x)
			a=	head_ref;
		else if((*head_ref)->data==y)
			b=head_ref;	
		
		head_ref=&((*head_ref)->next);
	}
	
	if(a&&b)
	{
		swap(*a,*b);
		swap(((*a)->next),((*b)->next));
	}
}



// boring searching and swapping : using two loops
void swap(Node** head_ref,int x,int y)
{
	//not considering a sorted LL
	if(x==y) return;
	
	//Search X
	Node* prevX =NULL,*currX=*head_ref;
	while(currX && currX->data!=x)
	{
		prevX=currX;
		currX=currX->next;
	}
	
	//Search Y
	Node* prevY=NULL,*currY=*head_ref;
	while(currY &&currY->data!=y)
	{
		prevY=currY;
		currY=currY->next;
	}
	
	if(currX==NULL || currY==NULL) return;
	
	//head conditions for X and Y
	if(prevX!=NULL)
		prevX->next=currY;
	else
		*head_ref=currY;
		
	if(prevY!=NULL)
		prevY->next=currX;
	else
		*head_ref=currX;
	
//	Swap
	Node* tmp=currY->next;
	currY->next=currX->next;
	currX->next=tmp;
		
}

int get_count(Node* c)
{
	int count=0;
	while(c!=NULL)
	{
		count++;
		c=c->next;
	}
	
	return count;
}

void printlist(Node* n)
{
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}
int main(){
	Node* head=NULL;
	for(int i=10;i>=1;i--)
		push(&head,i*10);
		
	printlist(head);
	
	swap(&head,20,50);
	printlist(head);
	
	new_swap(&head,10,100);
	printlist(head);
	
	return 0;
}
