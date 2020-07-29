#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int start,int mid,int end){
	
	int i,j,k;
	int s1=mid-start+1;
	int s2=end-mid;
	
	int L[s1];
	int R[s2];
	i=0,j=0,k=0;
	
	while(i<s1){
		L[i]=arr[start+i];
		i++;
	}
	
	while(j<s2){
		R[j]=arr[mid+j+1];
		j++;
	}
	
	i=0;j=0;
	k=start;
	
	while(i<s1 && j<s2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<s1){
		arr[k]=L[i];
		k++;
		i++;
	}
	while(j<s2){
		arr[k]=R[j];
		k++;
		j++;
	}
	
}

void mergesort(int arr[],int start,int end){
	if(start<end){
		int mid=(start+(end-1))/2;
		
		mergesort(arr,start,mid);
		mergesort(arr,mid+1,end);
		
		merge(arr,start,mid,end);
		
	}
	
}

int BinarySearch(int arr1[],int l,int r, int find){
	//recusion approach
	if(l<=r){ // use while loop here for iterative approach 
		int mid=l+(r-1)/2;
		
		if(arr1[mid]==find)
			return mid; 
			
		if(arr1[mid]<find)
			return BinarySearch(arr1,mid+1,r,find); 
		
		if(arr1[mid]>find)
			return BinarySearch(arr1,l,mid-1,find);		
	}
	return -1;
}

int main(){
	//performed on a sorted array
	int arr[10]={82,21,100,40,79,99,21,44,55,11};
	for(int i=0;i<10;i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	mergesort(arr,0,9);
	
	for(int i=0;i<10;i++)
	{
		cout << arr[i] << " ";
	}
	
	int find=100;
	
	int index=BinarySearch(arr,0,9,find);
	
	
	cout << "\n";
	if(index!=-1)
		cout << find << " found at " <<index <<endl;
	else
		cout << "not found"<<endl;
		
	return 0;
}
