#include<bits/stdc++.h>
using namespace std;

class Queue{
	public:
		int front,rear, size;
		unsigned capacity;
		int* array;
};

Queue* create(unsigned capacity)
{
	Queue* queue=new Queue();
	queue->capacity=capacity;
	
	queue->size=0;
	queue->front=0;
	
	queue->rear=capacity-1;
	queue->array= new int[(queue->capacity*sizeof(int))];
	cout<<queue->capacity<<" "<<queue->size<<" "<<queue->front<<" "<<queue->rear<<endl;
	return queue;
}


int isFull(Queue* queue)
{
	return(queue->size==queue->capacity);
}

int isEmpty(Queue* queue)
{
	return(queue->size==0);
}


//enqueue, dequeue, front, back

void enqueue(Queue* queue,int data)
{
	if(isFull(queue))
	{
		cout<<"The Queue is full\n";
		return;
	}
	
	queue->rear=(queue->rear+1)%queue->capacity;
	cout<<queue->rear<<endl;
	queue->array[queue->rear]=data;
	
	queue->size=queue->size+1;
	cout<<queue->size<<" "<<queue->front<<" "<<queue->rear<<" "<<data<<"\nEnqueued to queue!\n"<<endl;
}

int dequeue(Queue* queue)
{
	if(isEmpty(queue)
	{
		cout<<"The Queue is Empty\n";
		return INT_MIN;
	}

	int data=queue->array[queue->front];
	queue->front=(queue->front+1)%queue->capacity;
	
	queue->size=queue->size-1;
	cout<<queue->size<<" "<<queue->front<<" "<<queue->rear<<" "<<data<<"\nDequeued to queue!\n"<<endl;
	return data;
}

int front(Queue* queue)
{
	if(isEmpty(queue))
	{
		cout<<"No front! Queue is empty\n";
		return INT_MIN;
	}
	return (queue->array[queue->front]);
}

int rear(Queue* queue)
{
	if(isEmpty(queue))
	{
		cout<<"No rear! Queue is Empty\n";
		return INT_MIN;
	}
	return(queue->array[queue->rear]);
}

int main()
{
	Queue* queue= create(100);
	for(int i=1;i<80;i++){
		enqueue(queue,i);
	}
	
	cout<<dequeue(queue)<<"\n"<<endl;
	for(int i=1;i<10;i++)
	{
		dequeue(queue);
	}
	
	cout<<front(queue)<<endl;
	cout<<rear(queue)<<endl;
	return 0;
}

