// using STL for priority Queue
//	Priority queues are a type of container adapters, 
//	specifically designed such that the first element of
// 	the queue is the greatest of all elements in the queue 
// 	and elements are in non increasing order
//	
//Methods of Deque:
//	deque insert() 			function in C++ STL	: Inserts an element. And returns an iterator that points to the first of the newly inserted elements.
//	deque rbegin() 			function in C++ STL	: Returns a reverse iterator which points to the last element of the deque (i.e., its reverse beginning).
//	deque rend() 			function in C++ STL	: Returns a reverse iterator which points to the position before the beginning of the deque 
//													(which is considered its reverse end).
//	deque cbegin() 			in C++ STL			: Returns a constant iterator pointing to the first element of the container, that is, the 
//													iterator cannot be used to modify, only traverse the deque.
//	deque max_size() 		function in C++ STL	: Returns the maximum number of elements that a deque container can hold.
//	deque assign() 			function in C++ STL	: Assign values to the same or different deque container.
//	deque resize() 			function in C++ STL	: Function which changes the size of the deque.
//	deque::push_front() 	in C++ STL			: This function is used to push elements into a deque from the front.
//	deque::push_back() 		in C++ STL			: This function is used to push elements into a deque from the back.
//	deque::pop_front() 		in C++ STL			: This function is used to pop or remove elements from a deque from the front.
//	deque::pop_back() 		in C++ STL			: This function is used to pop or remove elements from a deque from the back.
//	deque::front()			in C++ STL			: This function is used to reference the first element of the deque container.
//	deque::back() 			in C++ STL			:  This function is used to reference the last element of the deque container.
//	deque::clear() 			in C++ STL			: This function is used to remove all the elements of the deque container, thus making its size 0
//	deque::erase() 			in C++ STL			: This function is used to remove elements from a container from the specified position or range.
//	deque::empty() 			in C++ STL			: This function is used to check if the deque container is empty or not.
//	deque::size() 			in C++ STL			: This function is used to return the size of the deque container or the number of elements in the deque container.
//	deque::operator= 		in C++ STL			: operator= operator is used to assign new contents to the container by replacing the existing contents.
//	deque::operator[] 		in C++ STL			: operator[] operator is used to reference the element present at position given inside the operator.
//	deque::at() 			in C++ STL			: This function is used reference the element present at the position given as the parameter to the function.
//	deque::swap()  			in C++ STL			: This function is used to swap the contents of one deque with another deque of same type and size.
//	deque::begin() 			in C++ STL			: This function is used to return an iterator pointing to the first element of the deque container.
//	deque::end  			in C++ STL			: This function is used to return an iterator pointing to the last element of the deque container.
//	deque::emplace_front() 	in C++ STL			: This function is used to insert a new element is added to the beginning of the deque.  
//	deque::emplace_back()  	in C++ STL			: This function is used to insert a new element is added to the end of the deque.

#include<bits/stdc++.h>
#include<deque>
using namespace std;

void display_DeQue(deque <int> dq)
{
	deque <int> :: iterator it;
	
	for(it=dq.begin();it!=dq.end();++it	)
	{
		cout<<"\t"<<*it;
	}
	cout<<"\n";
}

int main()
{
	deque<int> dq;
	cout<<"Enter 5 values to insert in the Deque"<<endl;
	
	dq.push_back(10); 
    dq.push_front(20);
	dq.push_front(30); 
    dq.push_back(40); 
    dq.push_front(15);
    dq.push_back(60);
    
	cout << "The deque gquiz is : "; 
    display_DeQue(dq); 
  
    cout << "\n dq.size() : " << dq.size(); 
    cout << "\n dq.max_size() : " << dq.max_size(); 
  
    cout << "\n dq.at(2) : " << dq.at(2); 
    cout << "\n dq.front() : " << dq.front(); 
    cout << "\n dq.back() : " << dq.back()<<endl; 
  
    cout << "\n dq.pop_front() : "; 
    dq.pop_front(); 
    display_DeQue(dq); 
  
    cout << "\n dq.pop_back() : "; 
    dq.pop_back(); 
    display_DeQue(dq); 
  
	return 0;
}

