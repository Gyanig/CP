#include <bits/stdc++.h>
using namespace std;

int main(){
	int n=0;
	
	cin >> n;
	if(n==2){
		cout<<1<<endl;
		return 0;
	}
	if(n==3){
		cout<<2<<endl;
		return 0;
	}
	unsigned long int sum=0,i=0;
	for(i=0;i<n;i++)
	{
		sum=sum+i;
//		cout<< i << "12312345532123452345 "<<sum <<endl;
		if(sum<=n){
//		continue;
		}
		else{
			i--;
			break;
		}
	}
	cout<<i<<endl;	
	
	return 0;
}
