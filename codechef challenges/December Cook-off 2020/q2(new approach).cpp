#include <iostream>
#define ll long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll x,y,N,K;
		cin>>x>>y>>N>>K;
		ll diff=abs(x-y)-1;// even or Odd
		ll size=N+1; //0,1......N
		ll p[size]={0};
		ll t[size]={0};
		p[x]=1;
		t[y]=1;
		for(int i=x;i<size;i+=k)
			p[i]=1;
		for(int i=x;i>=0;i-=k)
			p[i]=1;
		
		for(int j=y;i<size;j+=k)
			t[j]=1;
		for(int j=y;i>=0;j-=k)
			t[j]=1;
		
		for(int i=0;i<size;i++)
		{
			
		}		
	}

	return 0;
}

