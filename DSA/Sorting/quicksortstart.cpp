#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int lb,int ub)
{
	int pivot=arr[lb];
	int i=lb;
	int j=ub;
	while(i<j)
	{
		while(arr[i]<=pivot){
			i++;
		}
		
		while(arr[j]>pivot){
			j--;
		}
		
		if(i<j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		
		for(int u=0;u<8;u++)
		{
			cout<<arr[u]<<" ";
		}
		cout<<endl;
	}
	
//	int temp=arr[lb];
//	arr[lb]=arr[j];
//	arr[j]=temp;

	return j;
}

void quicksort(int arr[],int start, int end)
{
	if(start<end)
	{
		int pi=partition(arr,start,end);
		quicksort(arr,start,pi);
		quicksort(arr,pi+1,end);	
	}
}

int main(){
	cout << "Quick Sort \n";
	int a[7];
	cout << "Enter 8 numbers to sort \n";
	for(int i=0;i<8;i++)
		cin >> a[i];
	
	for(int i=0;i<8;i++)
		cout << a[i] << "\t";
		
	cout << "\n";
	
	quicksort(a,0,7);
	
	
	for(int i=0;i<8;i++)
		cout << a[i] << "\t";
		
	return 0;
}
