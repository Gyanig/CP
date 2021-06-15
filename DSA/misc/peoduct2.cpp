#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={10,3,6,8,9,4,3};
	int max=arr[1]-arr[0];
	int min=arr[0];
	for(int i=1;i<7;i++)
	{
		if(arr[i]-min>max)
		{
			max=arr[i]-min;
		}
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	cout<<"Max "<<max<<endl;
	return 0;
}
