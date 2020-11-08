#include<bits/stdc++.h>
using namespace std;

int main()
{
	set<int> a;
	int n;
	cin>>n;
	while(n--)
	{
		int check,input;
		cin>>check>>input;
		auto pos =a.find(input);
		if(check==1)
		{
			a.insert(input);
		}
		if(check==2)
		{
			if(pos!=a.end())
				a.erase(input);
		}
		if(check==3)
		{
			if(pos!=a.end())
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
	}
	return 0;
}

