// using STL for priority Queue
//	Priority queues are a type of container adapters, 
//	specifically designed such that the first element of
// 	the queue is the greatest of all elements in the queue 
// 	and elements are in non increasing order
//	
//	priority_queue::empty() 	in C++ STL– empty() function returns whether the queue is empty.
//	priority_queue::size() 		in C++ STL– size() function returns the size of the queue.
//	priority_queue::top() 		in C++ STL– Returns a reference to the top most element of the queue
//	priority_queue::push() 		in C++ STL– push(g) function adds the element ‘g’ at the end of the queue.
//	priority_queue::pop() 		in C++ STL– pop() function deletes the first element of the queue.
//	priority_queue::swap() 		in C++ STL– This function is used to swap the contents of one priority
//											 queue with another priority queue of same type and size.
//	priority_queue::emplace() 	in C++ STL– This function is used to insert a new element into the priority queue container, 
//											the new element is added to the top of the priority queue.
//	priority_queue::value_type 	in C++ STL– Represents the type of object stored as an element in a priority_queue. 
//											It acts as a synonym for the template parameter.

#include<bits/stdc++.h>
#include<queue>
using namespace std;

//uses MAX HEAP-	priority_queue <int> g= gq;
//FOR MIN HEAP- 	priority_queue <int, vector<int>, greater<int>> g = gq;

void display_priority_queue(priority_queue <int> pq)
{
	priority_queue <int> g= pq;
	
	while(!g.empty())
	{
		cout<<"\t"<<g.top();
		g.pop();
	}
	cout<<"\n";
}

int main()
{
	priority_queue<int> pq;
	cout<<"Enter 5 values to insert in the priority queue"<<endl;
	int k;
	
	for(int i=0;i<5;i++)
	{
		cin>>k;
		pq.push(k);
	}
	
	cout<<"Output queue: "<<endl;
	display_priority_queue(pq);
	
	cout<<"\n size of Priority Queue: "<<pq.size()<<endl;
	cout<<"\n Top element: "<<pq.top()<<endl;
	
	cout<<"\n Pop element done\n";
	pq.pop();
	
	display_priority_queue(pq);
	
	return 0;
}

