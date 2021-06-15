#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll sum=0;
//		ll arr[n];
		for(int i=0;i<n;i++)
		{
			ll inp;
			cin>>inp;
			sum+=inp;
		}
		if(sum%k==0)
		{
			cout<<"0"<<endl;
		}
		else
		{
//			ll rem=sum%k;
			cout<<"1"<<endl;
		}
	}


	return 0;
}


