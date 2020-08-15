#include <iostream> 
using namespace std; 

// A linked list node class 
class Node { 
	public: 
		int data; 
		class Node* next; 
	
		// constructor 
		Node(int val, Node* next) : data(val), next(next) {} 
	
		void printList() 
		{ 
			Node* node = this; 
			while (node != NULL) { 
				cout << node->data << " "; 
				node = node->next; 
			} 
			cout << endl; 
		} 
}; 

// Function to add a node 
// at the beginning of List 
void push(Node** head_ref, int new_data) 
{ 
	// allocate node using constructor 
	(*head_ref) = new Node(new_data, *head_ref); 
} 


void swap(Node*& a, Node*& b) 
{ 
	Node* temp = a; 
	a = b; 
	b = temp; 
	cout<< a->data<<" "<<b->data<<endl;
} 

void swapNodes(Node** head_ref,Node*head, int x, int y) 
{ 

	// Nothing to do if x and y are same 
	if (x == y) 
		return; 

	Node **a = NULL, **b = NULL; 

	// search for x and y in the linked list 
	// and store their pointer in a and b 
	while (*head_ref) { 
		if ((*head_ref)->data == x) { 
			a = head_ref; 
		} 
		else if ((*head_ref)->data == y) { 
			b = head_ref; 
		} 
//		cout<<head_ref<<" "<<((*head_ref)->data)<<endl;
		head_ref = &((*head_ref)->next);  //changing the value of the pointer address from one to next
	} 

	// if we have found both a and b 
	// in the linked list swap current 
	// pointer and next pointer of these 
	if (a && b) { 
		head->printList();
		swap(*a, *b); 
		head->printList();
		swap(((*a)->next), ((*b)->next)); 
		head->printList();
	} 
} 

// Driver code 
int main() 
{ 

	Node* start = NULL; 

	// The constructed linked list is: 
	// 1->2->3->4->5->6->7 
	push(&start, 7); 
	push(&start, 6); 
	push(&start, 5); 
	push(&start, 4); 
	push(&start, 3); 
	push(&start, 2); 
	push(&start, 1); 

	cout << "Linked list before calling swapNodes() "; 
	start->printList(); 

	swapNodes(&start,start, 6, 3); 

	cout << "Linked list after calling swapNodes() "; 
	start->printList(); 
} 

