//Quick select algorithm - smallest
//using median concept
#include<bits/stdc++.h>
using namespace std;

void swap(int * a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int findMedian(int arr[],int n)
{
	sort(arr,arr+n);
	return arr[n/2];
}

int partition(int arr[],int lb,int ub,int pivot)
{
	int i;
	for(i=lb;i<ub;i++)
	{
		if(arr[i]==pivot)
			break;
	}
	swap(&arr[i],&arr[ub]);
	
//	int pi=arr[ub];
	i=lb;
	for(int j=lb;j<=(ub-1);j++)
	{
		if(arr[j]<=pivot)
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
	if(k>0 && k<=(r-l+1))
	{
		//size of the array
		int n=r-l+1;
	
		int i;
		int m=(n+4)/5;
		int median[m];
		for(i=0;i<n/5;i++)
		{
			median[i]=findMedian(arr+l+i*5,5);
		}
		
		//if last group has less elements
		if((i*5)<n)
		{
			median[i]=findMedian(arr+l+i*5,n%5);
			i++;
		}
		
		
//		for(int l=0;l<m;l++)
//		{
//			cout<<median[l]<<endl;
//		}
		
		int mom= (i==1) ? median[i-1]:Kthsmallest(median,0,i-1,i/2);
		
		int pos=partition(arr,l,r,mom);
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
    int n = sizeof(arr) / sizeof(arr[0]); 
	int k = n/2; 
    cout << "K'th smallest element is " << Kthsmallest(arr, 0, n - 1, k); 
//	for(int i=0;i<n;i++)
//	{
//		cout<<arr[i]<<endl;
//	}
//	cout<<
	
	return 0;
}
