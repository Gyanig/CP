#include<bits/stdc++.h>
using namespace std;

void swap(int* a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int *arr,int lb,int ub,int *lp)
{
	if (arr[lb] > arr[ub]) 
        swap(&arr[lb], &arr[ub]); 
        
	int i=lb+1;
	
	int m=lb+1;
	int n=ub-1;
	
	int p1=arr[lb];
	int p2=arr[ub];
	
	while(m<=n){
//		for (int b = 0; b < 8; b++) 
//        	cout << arr[b] << " "; 
//    	cout << endl; 
		if(arr[m]<p1)
		{
			swap(&arr[m],&arr[i]);
			i++;
		}
		
		else if(arr[m]>=p2)
		{
			while(arr[n]>p2 && m<n){
				n--;
			}
			swap(&arr[m],&arr[n]);
			n--;
			
			if(arr[m]<p1)
			{
				swap(&arr[m],&arr[i]);
				i++;
			}
		}
		m++;	
	}
	i--;
	n++;
	
	
	swap(&arr[lb],&arr[i]);
	swap(&arr[ub],&arr[n]);
	
	*lp=i;
	
	return n;
}

void Twopivotquicksort(int* arr,int start, int end)
{
	if(start<end)
	{
		int lp,rp;
		rp=partition(arr,start,end,&lp);
		Twopivotquicksort(arr,start,lp-1);
		Twopivotquicksort(arr,lp+1,rp-1);
		Twopivotquicksort(arr,rp+1,end);	
	}
}


int main()
{
	int arr[] = { 24, 8, 42, 75, 29, 77, 38, 57 }; 
    Twopivotquicksort(arr, 0, 7); 
    cout << "Sorted array: "; 
    for (int i = 0; i < 8; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
	return 0;
}
