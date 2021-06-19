//STL
#include<bits/stdc++.h>
using namespace std;

void MaxHeapify(int arr[],int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<n && arr[l]>arr[i])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		MaxHeapify(arr,largest,n);
	}
}

void HeapSort(int arr[],int n)
{
	//build the first heap from array
	for(int i=(n/2)-1;i>=0;i--)
		MaxHeapify(arr,i,n);

	for(int i=n-1; i>0; i--)
	{
		swap(arr[0],arr[i]);
		MaxHeapify(arr,0,i);
	}	
}


void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
	cout<<endl;
}
int main()
{
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
	printArray(arr, n);

	HeapSort(arr, n);

    printf("\nSorted Heap array : ");
    printArray(arr, n);

	return 0;
}