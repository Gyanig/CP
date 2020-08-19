#include<bits/stdc++.h>
using namespace std;

void swap(int* a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
//iterative 
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

void quicksort(int arr[],int start, int end)
{
	int stack[end-start+1];
	
	int top=-1;
	
	stack[++top]=start;
	stack[++top]=end;
	
	while(top>=0)
	{
		end=stack[top--];
		start=stack[top--];
		
		int pi= partition(arr,start,end);
		
		if((pi-1) > start)
		{
			stack[++top]=start;
			stack[++top]=pi-1;
		}
		if((pi+1) < end)
		{
			stack[++top]=pi+1;
			stack[++top]=end;
		}
		cout<<stack[top]<<" "<<top<<endl;
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
