#include <bits/stdc++.h>

using namespace std;

void SentinelSearch(int arr[],int n,int findn){
	
	int last=arr[n-1];
	arr[n-1]=findn;
	int i=0;
	while(arr[i]!=findn){
		i++;
	}
	arr[n-1]=last;
	
	if((i<n-1) || (findn==arr[n-1])){
		cout << findn << "present at " << i<< endl;
	}
	else
		cout << "Not Found \n" ;
}


int main(){
	// Linear search 
	
	int a[10]={10,20,30,60,50,110,100,130,170};
	
	int find=175;
	int flag=-1;
	int index=-1;
	
	for(int i=0;i<10;i++)
	{
		if(a[i]==find)
		{
			index=i;
			flag=1;
		}
	}
	if(find==1)
		cout << "Number found at " << index <<endl ;
	else
		cout << "Number not found" <<endl;
		
		
	// Sentinel linear search	
	int b[10]={10,20,30,40,50,60,70,80,90,100};
	find=100;
	index=10;	
	
	SentinelSearch(b,index,find);
	
	return 0;
}
