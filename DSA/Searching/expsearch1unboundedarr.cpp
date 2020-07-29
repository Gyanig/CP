#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int low,int high);

// Let's take an example function  
// as f(x) = x^2 - 10*x - 20 Note that 
// f(x) can be any monotonocally increasing function  
int f(int x) { return (x*x - 10*x - 70); }  

int ExpoSearch(){
	if(f(0) > 0)
		return 0;
	
	int i=1;
	while(f(i)<=0)
		i=i*2;
//	
//	if(i>length){
//		i=length;
//	}
	
	int loc= BinarySearch(i/2,i);
//	cout << high << " "<<low<< " ";
	return loc;
}

int BinarySearch(int low,int high){
	if(high>=low){
		
		int mid= low + (high-low)/2;
		
		if(f(mid)>0 && (mid==low ||f(mid-1)<=0))
			return mid;
		
		if(f(mid)<=0)
			return BinarySearch((mid+1),high);	
			
		return BinarySearch(low,mid-1);
	}
	
	return -1; 
}

int main(){
//	int arr[10]={10,20,30,40,50,60,70,80,90,100};
	int index=ExpoSearch();
	cout << index << endl;
	return 0;
}

