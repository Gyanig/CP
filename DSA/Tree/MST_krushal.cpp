#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
//krushal's algo - uses disjoint sets 
//prim's algo is based on pqueue 

// no need of extra pair
// calculate value

int find_root(int node[],int v)
{
	while(node[v]!=v)
	{
		int t=node[v];
		node[v]=node[t];
		v=node[t];
	}
	return v;
}

int MST_krushal(pair<int,pair<int,int>>set[],int n,int m)
{
	int min=0;
	int x,y,c;
	int node[m];
	
	for(int i=0;i<m;++i) //to check if same node comes or not
	{
		node[i]=i;
	}
	
	for(int i=0;i<m;i++)
	{
		x=set[i].second.first;
		y=set[i].second.second;
		c=set[i].first;
		
		//check for same nodes or cycle 
//		root_x, root_y have to be different
		int root_x=find_root(node,x);
		int root_y=find_root(node,y);
		if(root_x!=root_y)
		{
			min=min+c;
			node[root_x]=node[root_y];
		}
	
	}
	return min;
}

int main()
{
	int n, m;
	cout<<"Enter n & m :";
	cin>>n>>m;	// krushal's algo 
	int w; // weight
	int cost=0,mincost=0;
	
	int a[m],b[m];
	pair<int, pair<int,int>> set[m];
	cout<<"Enter "<<m<<"value pairs "<<endl;
	for(int i=0;i<m;i++)
	{

		cin>>a[i]>>b[i]>>w;
		set[i]=make_pair(w,make_pair(a[i],b[i]));
	}
	
	
	sort(set,set+m); // based on edge weight increasing 
	cout<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<set[i].second.first<<" "<<set[i].second.second<<" "<<set[i].first<<endl;;
	}
	
	mincost=MST_krushal(set,n,m);
	cout<<mincost<<endl;
	return 0;
}
