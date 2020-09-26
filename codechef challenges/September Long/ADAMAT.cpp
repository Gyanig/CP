//#pragma GCC optimize("O1")
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n=0;
		scanf("%d",&n);
		if(n<4 || n>64)
		{
			printf("0\n");
			continue;
		}
		
		int a[n][n];
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);	
			}
		}
		
		// traverse either the top row or leftmost colomn
		//considering leftmost
		int cc=0;
		int k=n-1;
		
		while(k>=0)
		{
			if(a[0][k]!= (k+1))
			{
			    for (int x = 0; x < k+1; x++) 
			    {
				    for (int y = 0; y < x;y++) 
			        {
			        	
			        	int temp=a[x][y];
			            a[x][y] = a[y][x]; 
			            a[y][x]=temp;
//			            cout<<"transposed "<<a[x][y]<<" "<<a[y][x]<<endl;
			    	}
				}
				
//				for(int x = 0; x < n; x++)
//				{
//					for(int y = 0; y < n; y++)
//					{
//						printf("%d ",a[x][y]);
//					}
//					printf("\n");
//				}
				
				cc++;
			}
			k--;
		}
			
		printf("%d\n",cc);
		cc=0;
	}
	
	
	return 0;
}
