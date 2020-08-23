#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
};

void print(Node* n)
{
	Node* last=n;
	cout<<"DLL :"<<endl;
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		last=n;
		n=n->next;
	}
	cout<<endl;
	cout<<"Reverse DLL:"<<endl;
	while(last!=NULL){
		cout<<last->data<<" ";
		last=last->prev;
	}
	cout<<endl;
}

void push(Node** head_ref,int data)
{
	Node* new_node= new Node();
	new_node->data=data;
	
	new_node->next=(*head_ref);
	new_node->prev=NULL;

	if((*head_ref)!=NULL)
		(*head_ref)->prev=new_node;
	
	(*head_ref)=new_node;	
}


//find the end node - pivot
// using first node starting 
// write partiton 
// quicksort recusion returns head ref


void swap(int* a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
Node* tail_node(Node* cur)
{
	while(cur && cur->next!=NULL)
	{
		cur=cur->next;
	}
	return cur;
}

//{
//
//	int pivot=arr[ub];
//	int i=lb-1;
//	
//	for(int j=lb;j<=(ub-1);j++){
//		if(arr[j]<pivot)
//		{
//			i++;
//			swap(&arr[i],&arr[j]);
//		}
//	}
//	swap(&arr[i+1],&arr[ub]);
//	return (i+1);
//
//}

Node* partition(Node* head,Node*end)
{
	int pivot=end->data;
	Node* i=head->prev;
	
	//lomuto's approach
	for(Node* j = head;j!=end;j=j->next)
	{
		if(j->data <= pivot)
		{
			//i++
			i=(i==NULL)?head:i->next;
			
			swap(&(i->data),&(j->data));
		}
	}
	
	i=(i==NULL)?head:i->next;
	
	swap(&(i->data),&(end->data));
	return i;
}

Node* quicksort_recursion(Node* head, Node* end)
{	
	//base condition
	if(end!=NULL &&head!=end && head!=(end->next))
	{
		//using partition 
		Node* p=partition(head,end);
		//tail recursion
		quicksort_recursion(head,p->prev);
		quicksort_recursion(p->next,end);
	}
}

void quicksort(Node* head)
{
	// no need of the double pointer of the node, coz we are not change node positions
	Node* end=tail_node(head);
	quicksort_recursion(head,end);
}


int main(){
	
	Node* head=NULL;
	
	cout<<"Enter 10 data elements to sort"<<endl;
	int data;
	for(int i=10;i>0;i--)
	{
		cin>>data;
		push(&head,data);
	}
		
	
	print(head);
	
	quicksort(head);
	print(head);
	return 0;
}
