#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

unsigned long long int func(unsigned long long int n)
{
	return (n*(n+1))/2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll sum=(n*(n+1))/2;
		ll ans=0;
		if(sum & 1)
			ans=0;
		else
		{
			double t=sum/2;
			double k=(sqrt(8*t+1)/2)-0.5;
			double deci,inti;
			deci=modf(k,&inti);
			ll a=(ll)k;
			if(deci==0)
			{
				ans=func(a-1)+func(n-a-1);
			}	
			ans+=n-a;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}


