//Quick select algorithm - smallest

#include<bits/stdc++.h>
using namespace std;

void swap(int * a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int lb,int ub)
{
	int pi=arr[ub];
	int i=lb;
	for(int j=lb;j<(ub-1);j++)
	{
		if(arr[j]<=pi)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[ub]);
	return i;
}

int Kthsmallest(int arr[],int l,int r,int k)
{
	if(k>0 && k<=r-l+1)
	{
		int pos=partition(arr,l,r);
		if(pos-l == k-1)
			return arr[pos];
			
		if(pos-l >k-1)
			return Kthsmallest(arr,l,pos-1,k);
		//else
		return Kthsmallest(arr,pos+1,r,k-pos+l-1);			
	}
	return INT_MAX;
}

int main()
{
	
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 }; 
    int n = sizeof(arr) / sizeof(arr[0]), k = 7; 
    cout << "K'th smallest element is " << Kthsmallest(arr, 0, n - 1, k); 
	return 0;
}
