//DeQue : Double ended queues -  allows insert and delete at both ends
//(IMP)	: Deque supports both stack and queue operations, it can be used as both

//Methods:
//	insertFront(): Adds an item at the front of Deque.
//	insertLast(): Adds an item at the rear of Deque.
//	deleteFront(): Deletes an item from front of Deque.
//	deleteLast(): Deletes an item from rear of Deque.
//	
//	In addition to above operations, following operations are also supported
//	getFront(): Gets the front item from queue.
//	getRear(): Gets the last item from queue.
//	isEmpty(): Checks whether Deque is empty or not.
//	isFull(): Checks whether Deque is full or not.

//	Using LinkedList Approach
#include<bits/stdc++.h>
using namespace std;


class QNode{
	public:
		int data;
		QNode* next;

		QNode(int d)
		{
			data=d;
			next=NULL;
		}
			
};

class Queue{
//	friend class QNode;
	public:
		QNode* front,* rear;
		//initialize 
		
		Queue()
		{
			front=NULL;
			rear=NULL;
		}
		
		void EnQueuefront(int data)
		{
			QNode* new_qnode=new QNode(data);
			
			if(rear==NULL)
			{
				front= rear=new_qnode;
				cout<<"EnQueued front! "<<front->data<<endl;
				return;
			}
	
			new_qnode->next=front;
			front=new_qnode;
			cout<<"EnQueued front done! "<<front->data<<endl;
		
		}
		
		void EnQueuerear(int data)
		{
			QNode* new_qnode=new QNode(data);
			
			if(rear==NULL)
			{
				front= rear=new_qnode;
				cout<<"EnQueued rear! "<<rear->data<<endl;
				return;
			}
	
			rear->next=new_qnode;
			rear=new_qnode;
			cout<<"EnQueued rear done! "<<rear->data<<endl;
		
		}
		
		
		void DeQueuefront()
		{
			
			if(front==NULL)
			{
				cout<<"Empty"<<endl;
				return;
			}
			cout<<"DeQueued front! "<<front->data<<endl;
			QNode* remove_qnode=front;
			front=front->next;
			
			if(front==NULL)
			{
				rear=NULL;
			}
			
			delete(remove_qnode);
		}
		
		QNode* get_prev_last()
		{
			QNode* n= front;
			while((n->next)->next!=NULL)
			{
				n=n->next;
			}
			return n;
		}
		
		void DeQueuerear()
		{
			
			if(front==NULL)
			{
				cout<<"Empty"<<endl;
				return;
			}
			cout<<"DeQueued rear! "<<rear->data<<endl;
			QNode* remove_qnode=rear;
			QNode* prev_last=get_prev_last();
			prev_last->next=NULL;
			rear=prev_last;
			
			if(front==NULL)
			{
				rear=NULL;
			}
			
			delete(remove_qnode);
		}
		
		void printQueue(QNode* k)
		{
			cout<<"printlist:\n";
			while(k!=NULL)
			{
				cout<<k->data<<endl;
				k=k->next;
			}
			
		}
		
};


int main(){
	Queue obj;
	
	obj.EnQueuefront(10);
	obj.EnQueuerear(20);
	obj.EnQueuefront(30);
	obj.EnQueuefront(70);
	obj.EnQueuerear(5);
	obj.printQueue(obj.front);
	
	obj.DeQueuefront();
	obj.printQueue(obj.front);
	
	obj.DeQueuerear();
	obj.printQueue(obj.front);

	return 0;
}
