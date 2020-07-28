#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end){
	int pivot = arr[end];
	int i=start-1;
	
	for(int j=start;j<=(end-1);j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[i+1];
	arr[i+1]=arr[end];
	arr[end]=temp;
	
	for(int k=0;k<14;k++)
		cout << arr[k] <<"\t";
		
	cout<< "\n"; 	 
	return (i+1);
}

void quicksort(int arr[],int start, int end){
	if(start<end)
	{	
		int pi=partition(arr,start,end);
		quicksort(arr,start,pi-1);
		quicksort(arr,pi+1,end);
	}
	
}


int main(){
	
	cout << "Quick Sort \n";
	int a[14];
	cout << "Enter 14 numbers to sort \n";
	for(int i=0;i<14;i++)
		cin >> a[i];
	
	for(int i=0;i<14;i++)
		cout << a[i] << "\t";
		
	cout << "\n";
	
	quicksort(a,0,13);
	
	
	for(int i=0;i<14;i++)
		cout << a[i] << "\t";
		
		
	return 0;
}
