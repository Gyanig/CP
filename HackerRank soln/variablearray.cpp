#include<bits/stdc++.h>;
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	int num=0;
	vector<vector<int>> a;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		vector <int> v;
		for(int i=0;i<k;i++)
		{
			cin>>num;
			v.push_back(num);
		}
		a.push_back(v);
	}
	vector<vector<int>> que;
	int num2=0;
	for(int i=0;i<q;i++)
	{
		vector <int> v2;
		for(int i=0;i<2;i++)
		{
			cin>>num2;
			v2.push_back(num2);
		}
		que.push_back(v2);
	}
	
	for(i=0;i<q;i++)
	{
		int a1=que[i][0];
		int b1=que[i][1];
		cout<<a[a1][b1]<<endl;
	}
	
	
	return 0;
}
