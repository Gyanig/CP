#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int arrr[],int ,int ,int );

int ExpoSearch(int arr[],int length,int input){
	if(arr[0]==input)
		return 0;
	
	int i=1;
	while(i<=length && input>=arr[i])
		i*=2;
	
	if(i>length){
		i=length;
	}
	
	int loc= BinarySearch(arr,i/2,i,input);
//	cout << high << " "<<low<< " ";
	return loc;
}

int BinarySearch(int arr[],int low,int high,int input){
	if(low<high){
		
		int mid= low + (high-1)/2;
		
		if(arr[mid]==input)
			return mid;
		
		if(arr[mid]>input)
			return BinarySearch(arr,low, mid-1,input);	
			
		return BinarySearch(arr,mid+1,high,input);
	}
	
	return -1; 
}

int main(){
	int arr[10]={10,20,30,40,50,60,70,80,90,100};
	int index=ExpoSearch(arr,9,80);
	cout << index << endl;
	return 0;
}

