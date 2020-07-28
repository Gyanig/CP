#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		unsigned long int m, tc,th;
		cin >> m;;
		cin >> tc;
		cin >> th;
		
		int flag=0;
		if(tc==th)
			flag=1;
	
		int k=(th-tc)%3;
		int time=(th-tc)/3;
		
		if(k==0 && time<m){
			flag=1;
		}
		else
		{
			flag=0;
				}		

		if(flag==0){
			cout << "Yes\n";
		}
		else
			cout << "No\n";
		
	}	
	return 0;
}
