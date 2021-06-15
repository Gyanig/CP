#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={10,4,0,6,2};
	int p=1;
	for(int i=0;i<5;i++)
	{
		if(arr[i]!=0)
			p*=arr[i];
		else
			arr[i]=1;
	}
	cout<<"Output"<<endl;
	//if array ele
	for(int i=0;i<5;i++)
	{
		cout<<(p/arr[i])<<" ";
	}
	
}
