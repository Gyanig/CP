#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n]={0}; 
		
		/* approach should be take sum while taking input
			take normal sum first, check if sum=0 or not (base)
			further approach :
			suppose the number = ith position - consider it 0
			cant sort the array - that will change the order
			one by one I have to increment
			i have to keep the neg and pos in check
			if neg>pos - answer no
			if pos>neg - pos-i and if sum <0 -skip number
			if pos=neg yes			
		*/
		
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		
		if(sum==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			int neg=0;
			int pos=0;
			for(int i=0;i<n;i++)
			{
				
				if(arr[i]>=0)
				{
					pos+=arr[i];
				}
				if(arr[i]<0)
				{
					neg+=arr[i];
				}
				
				if((pos+neg)>0)
				{
					
					int diff=(i+1);
					
					if((pos-diff)>=0)
						pos=pos-(i+1);
						
				}
				cout<<"pos : "<<pos<<" neg : "<<neg<<endl;
			}
			
			if((pos+neg)==0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		
	}

	
	return 0;
}
