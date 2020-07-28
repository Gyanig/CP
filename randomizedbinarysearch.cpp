#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int getrandom(int x,int y){
	srand(time(NULL));
	return (x+rand() %(y-x+1));
}

int rbs(int arr[],int l,int r,int x){
	
	if(r>=l){
		int mid=getrandom(l,r);
		
		if(arr[mid]==x)
			return mid;
			
		if(arr[mid] >x)
			return rbs(arr,l,mid-1,x);
		
		return rbs(arr,mid+1,r,x);
	}
	
	return -1;
}
d
int main(void){
	int arr[10]={70,262,1231,355,123,445,235,123,88,1};
	
	int x =1;
	int result =rbs(arr,0,9,x);
	cout << result <<endl;
	return 0;
}
