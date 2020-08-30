//Circular Queue
//FIFO (First In First Out) like stacks and the last position is connected back 
//to the first position to make a circle. It is also called ‘Ring Buffer’

#include<bits/stdc++.h>
using namespace std;

class Queue{
	public:
		int front,rear;
		int size;
		int* arr;
		
		Queue(int s)
		{
			front=rear=-1;
			size=s;
			arr=new int[size];
		}
		
		void enqueue(int data);
		int dequeue();
		void display_cqueue();
		
};


//enqueue, dequeue, front, back

void Queue::enqueue(int data)
{
	if((front==0 && rear==size-1) || (rear== (front-1)%(size-1)))
	{
		cout<<"The Queue is full\n";
		return;
	}
	
	//first element
	else if(front == -1)
	{
		front=rear=0;
		arr[rear]=data;
		cout<<data<<" is Enqueued !"<<endl;
	}
	
	//if rear is at last and front is popped and has empty space
	else if(rear==size-1 && front!=0)
	{
		rear=0;
		arr[rear]=data;
		cout<<data<<" is Enqueued !"<<endl;
	}
	//normal enqueing
	else
	{
		rear++;
		arr[rear]=data;
		cout<<data<<" is Enqueued !"<<endl;
	}
	
}


int Queue::dequeue()
{
	if(front==-1)
	{
		cout<<"The Queue is Empty\n";
		return INT_MIN;
	}

	int data=arr[front];
	//indexing as -1
	arr[front]=-1;
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==size-1)
		front=0;
	else
		front++;
		
	return data;
}

void Queue::display_cqueue()
{
	
	if(front==-1)
	{
		cout<<"Queue is Empty!"<<endl;
		return;
	}
	cout<<"Circular Queue:"<<endl;
	
	if(rear>=front)
	{
		for(int i=front;i<=rear;i++)
			cout<<arr[i]<<" ";
			
		cout<<endl;	
	}
	else
	{
		for(int i=front;i<size;i++)
		{
			cout<<arr[i]<<" ";
		}
		for(int i=0;i<=rear;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	
}

int main()
{
	Queue cq(5); 
  
  	cq.display_cqueue();
    // Inserting elements in Circular Queue 
    cq.enqueue(14); 
    cq.enqueue(22); 
    cq.enqueue(13); 
    cq.enqueue(-6); 
  
    // Display elements present in Circular Queue 
    cq.display_cqueue(); 
  
    // Deleting elements from Circular Queue 
    cout<<"Deleted value = "<<cq.dequeue()<<endl; 
    cout<<"Deleted value = "<<cq.dequeue()<<endl; 
  
    cq.display_cqueue(); 
  
    cq.enqueue(9); 
    cq.enqueue(20); 
    cq.enqueue(5); 
  
    cq.display_cqueue(); 
  
    cq.enqueue(20); 
    cq.enqueue(10);
	
	return 0;
}

