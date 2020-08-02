#include<bits/stdc++.h>
using namespace std;

int main(){
	double N,D;
	cin>>N;
	cin>>D;
	int count=0;
	while(N--){
		double p,q;
		cin>>p;
		cin>>q;
		double dov=sqrt(p*p+q*q);
		if(dov<=D){
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
