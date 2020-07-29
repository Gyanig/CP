#include <bits/stdc++.h>
using namespace std;

int mbs(vector<int> A ,int key){
	
	int n=(int)A.size(); //returns the no pf elements
	
	int lg=log2(n-1)+1; // returns the lasrgest array index no of bits
		
	int pos=0;
	for(int i=lg;i>=0;i--){
		if(A[pos] == key)
			return pos;
			
		int new_pos = pos | (1<<i);
		
		if((new_pos<n) && (A[new_pos]<=key)){
			pos=new_pos;
		}		
	}
	
	return ((A[pos]==key)?pos:-1);	

 }


int main(){

	vector<int> A{-2,10,100,250,32315};
	cout <<mbs(A,-2) <<endl;	
	return 0;
}
