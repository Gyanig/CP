#include<bits/stdc++.h>
using namespace std;

//push(),pop(),isEmpty(),peek()

//bool push(int data) 	:++top returns if push was success! takes data
//int peek() 			:returns the element on the top of stack
//int pop()				: returns the popped element value
//bool isEmpty()		:returns if top is -1 or not

#define MAX 1000

class Stack{
	
	int top;
	public:
		int arr[MAX];
		Stack(){
			top=-1;
		}
		
		bool push(int data);
		int pop();
		int peek();
		bool isEmpty();
		int display();
};

bool Stack::push(int data)
{
	if(top >= MAX-1)
	{
		cout<<"Stack overflow"<<endl;
		return false;
	}
	else
	{
		arr[++top]=data;
		cout<<data<<" : pushed onto the stack\n";
		return true;	
	}	
} 

int Stack::pop()
{
	if(top<0)
	{
		cout<<"stack undeflow"<<endl;
		return 0;
	}
	else
	{
		int popped = arr[top--];
		cout<<popped<<" : removed from stack\n";
		return popped;
	}
}

int Stack::peek()
{
	if(top<0)
	{
		cout<<"Stack is empty";
		return 0;
	}
	else
	{
		return arr[top];
	}
}

bool Stack::isEmpty()
{
	if(top<0)
		return true;
	else
		return false;
}

int Stack::display()
{
	return top;
}

int main(){
	class Stack obj;
	obj.push(10);
	obj.push(20);
	obj.push(30);
	cout<<obj.peek()<<" : Top element \n";
	cout<<obj.pop()<<" : Top element popped \n Top value : "<<obj.display()<<endl;
	cout<<obj.peek()<<" : Top element \n";	
	
	return 0;
}




