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
		cin>>x>>y>>K>>N;
		ll x1,y1;
		if(x>y)
		{
		       x1=y;
		       y1=x;	
		}
		else
		{
		       x1=x;
		       y1=y;	
		}
		while(x1<y1)
		{
		 	if(x1==y1)
		 	{
			 cout<<"Yes\n";	
			 break;
			 }
		 	x1+=K;
			 y1-=K; 
		}
		if(x1==y1)
			  cout<<"Yes\n";
		else
		    	  cout<<"No\n";	
			
	}

	return 0;
}

