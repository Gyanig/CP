#include<bits/stdc++.h>
using namespace std;

int digits(unsigned long int num){
	int d;
	int sum=0;
	while(num!=0){
		d=num%10;
		sum+=d;
		num/=10;
	}
	return sum;
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n=0;
		cin >> n;
		unsigned long long int A[n],B[n];
		int c1=0,c2=0;
		int i=0;
		for(i=0;i<n;i++)
		{
			cin >> A[i] ;
			cin >> B[i] ;
			int s1=digits(A[i]);
			int s2=digits(B[i]);
			if(s1>s2 )
				c1++;
			if(s2>s1)
				c2++;
			if(s1==s2){
				c1++;
				c2++;
			}	
			
		}
		
		if(c1>c2)
			cout<<0<<" "<<c1<<endl;
		else if(c2>c1)
			cout <<1<<" "<<c2<<endl;
		else 
			cout <<2<<" "<<c1<<endl;	
	}
	
	return 0;
}
