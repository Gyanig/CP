#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<string,int> a;
	int n;
	cin>>n;
	while(n--)
	{
		int check,input2;
		string input1;
		cin>>check;
		
	 //find the string 
		if(check==1)
		{
			cin>>input1>>input2;
			a[input1]+=input2;

		}
		if(check==2)
		{
			cin>>input1;
			a[input1]=0;

		}
		if(check==3)
		{
			cin>>input1;
			cout<<a[input1]<<endl;
		}
	}
	return 0;
}

