#include<iostream>
#include<algorithm>
using namespace std;

bool sumsubsetK(int a[],int n,int sum)
{
	bool subset[2][sum + 1]; 
  
    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= sum; j++) { 
  
            // A subset with sum 0 is always possible  
            if (j == 0) 
                subset[i % 2][j] = true;  
  
            // If there exists no element no sum  
            // is possible  
            else if (i == 0) 
                subset[i % 2][j] = false;  
            else if (a[i - 1] <= j) 
                subset[i % 2][j] = subset[(i + 1) % 2] 
             [j - a[i - 1]] || subset[(i + 1) % 2][j]; 
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j]; 
        } 
    } 
  
    return subset[n % 2][sum]; 
}



int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long int k=0;
		scanf("%d",&k);
		int n=0;
		scanf("%d",&n);
		int a[n]={0};
		int i=0;
		while(i<n){
			scanf("%d",&a[i]);
			i++;
		}
		
		sort(a,a+n);
		
		if(sumsubsetK(a,n,k)==true)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
