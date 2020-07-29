#include <bits/stdc++.h>
using namespace std;

int jumpsearch(int arr[],int n,int find){
	
	int k=sqrt(n);
	
	int l=0,r=k;
	
	for(int i=0;i<n;){
		
		//cout << i << " " ;
		
		if(arr[i]==find){
			cout << i << " ";
			return i;
		}
		if(arr[i]>=find){
			//cout << i <<" ";
			l=i-k-1;
			r=i;
			break;
		}
		
		if((i+k)>n && i<n)
			i++;
		else
			i+=k;		
	}
	
	
	for(int j=l;j<r;j++){
		if(arr[j]==find){
			
			return j;
		}
	}
	
	return -1;
}

int main(){
	cout << "Jump Search" << endl;
	
	int arr[]={10,22,40,50,61,70,80,90,99,100};
	int index = jumpsearch(arr,10,70);
	cout << index << " "; 
	return 0;
}
