#include <iostream>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int b[n];
    	int p=0,a=0;
    	for(int i=0;i<n;i++)
    	{
		cin>>p;
		if(p==0)
		       a++;
			    
        }
	p=n-a;
	float pass=((float)p/(float)n)*100;
    	if(pass>=75)
		    cout<<"NO"<<endl;
	else
	    cout<<"YES"<<endl;
    }


    return 0;
}

