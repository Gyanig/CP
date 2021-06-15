#include<iostream>
#define ll long long
using namespace std;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b,i=1,j=1;
		cin>>a>>b;
		ll x,y,z=0;
		x=a*b*i;
		y=a*(b+j);
		z=x+y;	
		if(a!=b && z%(a*b)==0)
		{
			cout<<"YES"<<endl;
			cout<<x<<" "<<y<<" "<<z<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}


