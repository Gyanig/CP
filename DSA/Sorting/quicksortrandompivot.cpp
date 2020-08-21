//Lumoto's Partition scheme

#include<bits/stdc++.h>
using namespace std;

void swap(int* a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int lb,int ub)
{
	int pivot=arr[ub];
	int i=lb-1;
	
	for(int j=lb;j<=(ub-1);j++){
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[ub]);
	return (i+1);

}
int partition_r(int arr[],int start,int end)
{
	srand(time(NULL));
	int random=start+ rand()%(end-start);
	swap(&arr[random],&arr[end]);
	return partition(arr,start,end);
}

void quicksort(int arr[],int start, int end)
{
	if(start<end)
	{
		int pi=partition_r(arr,start,end);
		quicksort(arr,start,pi-1);
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
