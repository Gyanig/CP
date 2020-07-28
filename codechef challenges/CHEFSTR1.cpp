#include <bits/stdc++.h>
using namespace std;

int main(){
	int t=0;
	cin >> t;
	while(t--){
		long int n=0;
		cin>> n;
		long int s[n];
		long int sum=0;
		for(int i=0;i<n;i++){
		 	cin>>s[i];
		 	if(i>0 && i<n && s[i]!=s[i-1])
			{
				long int diff=s[i-1]-s[i];
		 		sum=sum+abs(diff)-1;
//		 		cout << s[i-1] <<" "<<s[i] <<" "  <<diff<<" " <<sum <<endl;	
			}
		}
		cout<< sum <<endl;
	}
	
	return 0;
}

