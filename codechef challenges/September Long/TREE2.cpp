//#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int nextminimum(unsigned long long int a[],unsigned long long int n,unsigned long long int cp)
{	
	cp=0;
	//base condition
	if(a[0]==0)
	{
		return cp;
	}
	
	//if same height is reached
	if(a[0]==a[n-1])
	{
		return cp+1;
	}

	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]==0)
			break;
		if(a[i]==a[i+1])
			continue;
		else
			cp++;	
	}
	return cp+1;

}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
// 		cin>>n;
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		unsigned long long int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%llu",&a[i]);
            // cin>>a[i];
		}

		sort(a,a+n,greater<int>());

		// cases : same height at first - find the next minimum length 
		//					- tallest comes from last in the arranged lengths
		//		 : different lengths - find tallest and cut one
		//		 : work till, every stick is same length entire : could be 1 or 2 even 
		//				- just check first and last element 
		
		unsigned long long int co=0;
		unsigned long long int m=0;
		m=nextminimum(a,n,co);
		printf("%llu\n",m);
// 		cout<<m<<endl;
		m=0;
	}
	
	return 0;
}
