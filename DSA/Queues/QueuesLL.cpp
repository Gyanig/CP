#include<bits/stdc++.h>
using namespace std;

//no use of capacity 
// just track the front and rear with te pointers

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
	
	public:
		QNode* front,* rear;
		//initialize 
		Queue()
		{
			front=NULL;
			rear=NULL;
		}
		
		void EnQueue(int data)
		{
			QNode* new_qnode=new QNode(data);
			
			if(rear==NULL)
			{
				front= rear=new_qnode;
				cout<<"EnQueued! "<<rear->data<<endl;
				return;
			}
	
			rear->next=new_qnode;
			rear=new_qnode;
			cout<<"EnQueued! "<<rear->data<<endl;
		}
		
		void DeQueue()
		{
			if(front==NULL)
			{
				cout<<"Empty"<<endl;
				return;
			}
			cout<<"DeQueued! "<<front->data<<endl;
			QNode* remove_qnode=front;
			front=front->next;
			
			if(front==NULL)
			{
				rear=NULL;
			}
			
			delete(remove_qnode);
		}
		
};


int main(){
	Queue obj;
	
	obj.EnQueue(10);
	obj.EnQueue(20);
	obj.DeQueue();
//	obj.DeQueue();
//	obj.DeQueue();
	obj.EnQueue(30);
	obj.EnQueue(100);
	obj.DeQueue();
	
	
	return 0;
}
