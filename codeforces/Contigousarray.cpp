#include<bits/stdc++.h>
using namespace std;

int findMaxLength(int nums[]) {
		int l=sizeof(nums)/sizeof(nums[0]);
        int arr[2 * l + 1]={-2};
        arr[l] = -1;
        int maxlen = 0, count = 0;
        for (int i = 0; i < l; i++) {
            count = count + (nums[i] == 0 ? -1 : 1);
            if (arr[count + l] >= -1) {
                maxlen = max(maxlen, i - arr[count + l]);
            } else {
                arr[count + l] = i;
            }

        }
        return maxlen;
}

int main()
{
	unsigned int n;
	cin>>n;
	char a[n];
	int b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]=='L')
			b[i]=1;
		else
			b[i]=0;	
	}
	
	int k=findMaxLength(b);
	cout<<k<<endl;
	
	
	return 0;
}
