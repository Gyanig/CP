#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int s=0;
		cin>>s;
		int cases=s-1;
		for(int i=0; i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(i==0 && j==0)
				{
					cout<<"0";
					continue;
				}
				
				if(cases>0)
				{
					cases-=1;
					cout<<".";
				}
				else
					cout<<"X";
					
					
			}
			cout<<"\n";
		}
	}
	return 0;
}
