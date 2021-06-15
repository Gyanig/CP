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
    	int p=0,a=0;
    	for(int i=0;i<n;i++)
    	{
		cin>>p;
		if(p==0)
			a++;
        }
	p=n-a;
	if(n<120)
 	        p=p+(120-n);
 	        
	float pass=((float)p/120.0)*100;
	cout<<pass<<" "<<p<<" "<<a;
    	if(pass>=75)
	        cout<<"YES"<<endl;
	else
	        cout<<"NO"<<endl;
    }


    return 0;
}

