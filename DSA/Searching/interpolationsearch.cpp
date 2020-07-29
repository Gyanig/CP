#include <bits/stdc++.h>
using namespace std;

int interpolationsearch(int arr[],int key, int n){
	int low=0;
	int high=n-1;
	
	int pos;
	
	while(low<=high){
		if(low==high){
			if(arr[low]==key)
				return low;
			else -1;	
		}
		
		pos= low + (((high-low)*(key-arr[low]))/(arr[high]-arr[low]));
			
		if(arr[pos]==key){
			return pos;
		}
		
		if(arr[pos]>key){
			high=pos-1;
		}
		
		else{
			low=pos+1;
		}
	}
	return -1;
	
}

int main(){
	int arr[]={8,8,8,8,8,8};
	int n=6;
//	int key=100;
	int index=interpolationsearch(arr,8,6);
	cout << index <<endl;
	
	return 0;
}
