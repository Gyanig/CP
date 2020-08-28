#include <iostream> 
#include <vector> 
using namespace std; 
int main() 
{ 
    vector<int> v = { 1, 2, 3 }; 
    vector<int>::iterator i; 
    int j; 
    cout << "Without iterators = "; 
    for (j = 0; j < 3; ++j)  
    { 
        cout << v[j] << " "; 
    } 
  
    cout << "\nWith iterators = "; 
    for (i = v.begin(); i != v.end(); ++i) 
    { 
        cout << *i << " "; 
    } 
  	
	// Inserting element using iterators 
    for (i = v.begin(); i != v.end(); ++i) { 
        if (i == v.begin()) { 
            i = v.insert(i, 5); 
            // inserting 5 at the beginning of v 
        } 
    }
	
	cout << "\nWith iterators = "; 
    for (i = v.begin(); i != v.end(); ++i) 
    { 
        cout << *i << " "; 
    } 
    
	// Deleting a element using iterators 
    for (i = v.begin(); i != v.end(); ++i) { 
        if (i == v.begin() + 1) { 
            i = v.erase(i); 
            // i now points to the element after the 
            // deleted element 
        } 
    }  
  	
  	cout << "\nWith iterators = "; 
    for (i = v.begin(); i != v.end(); ++i) 
    { 
        cout << *i << " "; 
    } 
    return 0; 
} 
