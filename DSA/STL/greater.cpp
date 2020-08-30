// C++ program to illustrate std::greater 

#include <algorithm> 
#include <functional> 
#include <iostream> 
using namespace std; 

void printArray(int arr[], int n) 
{ 

	for (int i = 0; i < n; i++) { 
		cout << arr[i] << ' '; 
	} 
	cout<<endl;
}

int main() 
{ 

	int arr[] = { 60, 10, 80, 40, 30, 20, 50, 90, 70 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	sort(arr, arr + 9);
	printArray(arr, n); 
	sort(arr, arr + 9, greater<int>()); 
	printArray(arr, n); 

	return 0; 
} 

