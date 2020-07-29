#include <bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int )
{
}

int bs1(int A[],int l, int r, int key){ 
    int m; 
  
    while( r - l > 1 ) 
    { 
        m = l + (r-l)/2; 
  
        if( A[m] <= key ) 
            l = m; 
        else
            r = m; 
    } 
  
//    if( A[l] == key ) 
//        return l; 
//    if( A[r] == key ) 
//        return r; 
//    else
    return A[l]; 
}
int BinarySearchIndexOfMinimumRotatedArray(int A[], int l, int r) 
{ 
    // extreme condition, size zero or size two 
    int m; 
  
    // Precondition: A[l] > A[r] 
    if( A[l] <= A[r] ) 
        return l; 
  
    while( l <= r ) 
    { 
        // Termination condition (l will eventually falls on r, and r always 
        // point minimum possible value) 
        if( l == r ) 
            return l; 
  
        m = l + (r-l)/2; // 'm' can fall in first pulse, 
                        // second pulse or exactly in the middle 
  
        if( A[m] < A[r] ) 
            // min can't be in the range 
            // (m < i <= r), we can exclude A[m+1 ... r] 
            r = m; 
        else
            // min must be in the range (m < i <= r), 
            // we must search in A[m+1 ... r] 
            l = m+1; 
    } 
  
    return -1; 
} 
  
int BinarySearchIndexOfMinimumRotatedArray(int A[], int size) 
{ 
    return BinarySearchIndexOfMinimumRotatedArray(A, 0, size-1); 
} 

int main(){
	// problems as ubiquitious binary search set 1
	
	//p1 - least number of comparisions 
	int A[] = {-1, 2, 3, 5, 6, 8, 9, 10};
	int find =8;
	int index = bs1(A,0,7,find);
	if(index!=-1)
		cout << index <<endl;
	else
		cout << "not found"<<endl;
	
	//p2 - count the duplicated elements 
	
	//p3- rotated array 
	int arr[10]={6,7,8,9,10,1,2,3,4,5};
	
	int min=BinarySearchIndexOfMinimumRotatedArray(arr,10);
	if(min!=-1)
		cout << min << endl;
	else
		cout << min <<endl;
	
	return 0;
}
