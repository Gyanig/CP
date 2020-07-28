#include <bits/stdc++.h>
using namespace std;

void swap(int *m, int *n){
	int t=*m;
	*m=*n;
	*n=t;
}

int partition(int a[],int p, int q){
	int pivot=a[q];
	int i=p-1;
	
	for(int j=i+1;j<q;i++)
	{
		if(a[j]<pivot)
		{
			i++;
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[i+1],&a[q]);
	
	return i+1;
}

void quicksort(int a[],int i,int j)
{
	if(i<j)
	{
		int pi=partition(a,i,j);
		quicksort(a,i,pi-1);
		quicksort(a,pi+1,j);
	}
	
}

int main(){
	int n;
	cin >> n;
	int a[n];
	
	for(int i=0;i<n;i++)
		cin >>a[i];
	//unsorted array
	for(int i=0;i<n;i++)
		cout<< a[n] << " ";
	
	cout << "\n";
	
	quicksort(a,0,n-1);
	
	//sorted array
	for(int i=0;i<n;i++)
		cout<< a[n] << " ";
	
	cout << "\n";
	return 0;
}
