#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long int D,P;
		cin>>D;
		cin>>P;
		while(D>10 && P>10)
		{
			D=D-P;
			P=P/2;
		}
		if(P>=(D*0.5+2) || P>=D)
			cout<<1<<endl;
		else
			cout<<0<<endl;	
		cout<<D<<" "<<P<<endl;
	}
	return 0;
}
