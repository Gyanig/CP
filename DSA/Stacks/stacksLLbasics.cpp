#include<bits/stdc++.h>
using namespace std;

//push(),pop(),isEmpty(),peek()

//bool push(int data) 	:++top returns if push was success! takes data
//int peek() 			:returns the element on the top of stack
//int pop()				: returns the popped element value
//bool isEmpty()		:returns if top is -1 or not

//using LinkedList, implement stacks

#define MAX 1000

class Node{
	public:
		int data;
		Node* next;
};

//last element of the stack is nothing but root denoted


Node* create(int data)
{
	Node* new_node=new Node();
	new_node->data=data;
	new_node->next=NULL;
	return new_node;
}
// not need for this as node covers up
//class Stack{
//	
//	int top;
//	public:
//		
//		
//		bool push(int data);
//		int pop();
//		int peek();
//		bool isEmpty();
//		int display();
//};

int isEmpty(Node* top)
{
	return !top;
}

void push(Node** top,int data)
{
	Node* new_node=create(data);
	new_node->next=(*top);
	(*top)=new_node;
	cout<<data<<" pushed to stack\n";
}

int pop(Node** top)
{
	if(isEmpty(*top))
	{
		cout<<"Stack is empty"<<endl;
		return 0; //returns -0 if empty
	}
	
	Node* popped=(*top);
	(*top)=(*top)->next;
	int popdata=popped->data;
	delete popped;
	return popdata;
}


int peek(Node* top)
{
	if(isEmpty(top))
	{
		cout<<"Stack is empty"<<endl;
		return 0;	
	}
	else
	{
		return(top->data);
	}
}


int main(){
	Node* top =NULL;
	
	push(&top,10);
	push(&top,20);	
	push(&top,30);	
	
	cout<< pop(&top) << " popped from the stack \n";
	cout<< pop(&top) << " popped from the stack \n";
	cout<< pop(&top) << " popped from the stack \n";
	cout<< peek(top)<<" : top \n";
	
	return 0;	
}
