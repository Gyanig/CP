#include<bits/stdc++.h>
using namespace std;
//LL:
//no use of capacity 
//just track the front and rear with te pointers


//Priority Queue, priority is a probability in a queue

class QNode{
	public:
		int data;
		int priority; 	
		
		//range 0-100 for convience
		// some doubts will arise as 
		//	1.	priority being same for all elements 
		// 	2.	priority is based? What is the application
		// 	3.	cant we have a better representation of prority queues using a tree based placement
		//	4. 	based on data, we can set different priority reasons
						 
		QNode* next;

		QNode(int d,int p)
		{
			data=d;
			priority=p;
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
		
		void EnQueue(int data,int priority)
		{
			QNode* new_qnode=new QNode(data,priority);
			
			if(rear==NULL)
			{
				front= rear=new_qnode;
				cout<<"EnQueued! "<<rear->data<<" "<<rear->priority<<endl;
				return;
			}
	
			rear->next=new_qnode;
			rear=new_qnode;
			cout<<"EnQueued! "<<rear->data<<" "<<rear->priority<<endl;
		
		}
		
		QNode* highestPriority()
		{
			
			QNode* n=front;
			QNode* prev=NULL;		//store the prev element of the highest
			int MAX=n->priority; 	// what if the first element has the highest priority
			
			while((n->next)!=NULL)
			{
				if((n->next)->priority>=MAX)
				{	
					MAX=(n->next)->priority;
					prev=n;
				}
				n=n->next;
			}
			
			cout<<"Inside highest Priority details:\nMAX:"<<MAX<<" \tprev node data:"<<prev->data<<" \tprev node priority:"<<prev->priority<<endl;
			
			return prev;
		}
		
		void DeQueue()
		{
			
			if(front==NULL)
			{
				cout<<"Empty"<<endl;
				return;
			}
			
			QNode* prev_node=highestPriority();
			
			cout<<"Outside Highest priority details: \n delete node data: "<<(prev_node->next)->data<<"\t delete node priority: "<<(prev_node->next)->priority<<endl;
			
			if(prev_node==rear)
			{
				cout<<"Last"<<endl;
			}
			
			cout<<"DeQueued! MAX priority:"<<(prev_node->next)->priority<<endl;
			
			QNode* tmp=(prev_node->next)->next;
			delete(prev_node->next);
			prev_node->next=tmp;
			
//			if(front==NULL)
//			{
//				rear=NULL;
//			}
//		
//			delete(tmp);
		}
		
		
		void printlist(QNode* k)
		{
			cout<<"printlist:\n";
			while(k!=NULL)
			{
				cout<<k->data<<" "<<k->priority<<endl;
				k=k->next;
			}
			
		}
		
};


int main(){
	Queue obj;
	
	obj.DeQueue();
	
	obj.EnQueue(10,50);
	obj.printlist(obj.front);
	obj.EnQueue(20,60);
	obj.printlist(obj.front);
	obj.EnQueue(80,5);
	obj.printlist(obj.front);
	obj.EnQueue(55,39);
	obj.printlist(obj.front);
	obj.EnQueue(5,44);
	obj.printlist(obj.front);
	obj.DeQueue();
	obj.printlist(obj.front);
	cout<<"front :"<<(obj.front)->data<<"\t rear:"<<obj.rear->data<<endl;
	obj.EnQueue(30,99);
	cout<<"front :"<<(obj.front)->data<<"\t rear:"<<obj.rear->data<<endl;
	obj.printlist(obj.front);
	
	obj.EnQueue(100,20);
	cout<<"front :"<<(obj.front)->data<<"\t rear:"<<obj.rear->data<<endl;
	obj.printlist(obj.front);
	obj.DeQueue();
	obj.printlist(obj.front);
	
	
	return 0;
}
