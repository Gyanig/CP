#include <bits/stdc++.h> 
using namespace std; 

//using structures instead of class
struct QNode 
{ 
	int data; 
	struct QNode* next; 
}; 

// LL approach Circular queue 
struct Queue 
{ 
	struct QNode *front, *rear; 
}; 

void enqueue(Queue* cq, int data) 
{ 
	struct QNode *tmp = new QNode; 
	tmp->data = data; 
	
	if (cq->front == NULL) 
		cq->front = tmp; 
	else
		cq->rear->next = tmp; 

	cq->rear = tmp; 
	cq->rear->next = cq->front; 
} 

// Function to delete element from Circular Queue 
int dequeue(Queue* cq) 
{ 
	if (cq->front == NULL) 
	{ 
		printf ("Queue is empty"); 
		return INT_MIN; 
	} 
	
	int data; // Value to be dequeued 
	
	// If this is the last node to be deleted 
	if (cq->front == cq->rear) 
	{ 
		data = cq->front->data; 
		delete (cq->front); 
		cq->front = NULL; 
		cq->rear = NULL; 
	} 
	else // a queue exists 
	{ 
		struct QNode *tmp = cq->front; 
		data = tmp->data; 
		cq->front = cq->front->next; 
		cq->rear->next= cq->front; 
		delete (tmp); 
	} 

	return data ; 
} 

void display_cqueue(struct Queue* cq) 
{ 
	struct QNode* tmp = cq->front; 
	printf("\nElements in Circular Queue are: "); 
	while (tmp->next != cq->front) 
	{ 
		cout<<tmp->data<<" "; 
		tmp = tmp->next; 
	} 
	cout<<tmp->data<<" "<<endl; 
} 

int main() 
{ 
	// Create a queue and initialize front and rear 
	Queue *cq = new Queue; 
	cq->front = cq->rear = NULL; 

	// Inserting elements in Circular Queue 
	enqueue(cq, 14); 
	enqueue(cq, 22); 
	enqueue(cq, 6); 
	enqueue(cq, 4); 
	enqueue(cq, 32); 
	enqueue(cq, 16); 
	
	// Display elements present in Circular Queue 
	display_cqueue(cq); 

	// Deleting elements from Circular Queue 
	cout<<"Deleted value = "<<dequeue(cq)<<endl; 
	cout<<"Deleted value = "<<dequeue(cq)<<endl; 

	// Remaining elements in Circular Queue 
	display_cqueue(cq); 

	enqueue(cq, 9); 
	enqueue(cq, 20); 
	display_cqueue(cq); 

	return 0; 
} 

