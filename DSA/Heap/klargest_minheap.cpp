//STL
#include<bits/stdc++.h>
using namespace std;

void MinHeapify(int arr[],int i,int n)
{
	if(i>=n/2) return;
	int l=2*i+1;
	int r=2*i+2;
	int smallest=i;
	if(arr[l]<arr[i])
		smallest=l;
	if(r<n && arr[r]<arr[smallest])
		smallest=r;
	if(smallest!=i)
	{
		swap(arr[i],arr[smallest]);
		MinHeapify(arr,smallest,n);
	}
}



void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
	cout<<endl;
}

void Kelement(int arr[],int n,int k)
{
	//build the first heap from array
	for(int i=n/2-1; i>=0; i--)
		MinHeapify(arr,i,n);

	printArray(arr, n);
	for(int i=n-1; i>n-k-1; i--)
	{
		swap(arr[n-1],arr[i]);
		MinHeapify(arr,n-1,i);
	}
}

int main()
{
    int arr[] = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
	printArray(arr, n);
	int k=3;
	Kelement(arr, n,k);
	// for(int i=n-k;i<n;i++)
	// 	cout<<arr[i]<<" ";

	// cout<<endl;

	printArray(arr,n);
	return 0;
}