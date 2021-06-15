#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void printFrequency(string str)
{
    // Define an unordered_map
    unordered_map<char, int> M;
    int a[str.length()];
    for (int i = 0; str[i]; i++) 
    {
        if (M.find(str[i]) == M.end()) 
        {
            M.insert(make_pair(str[i], 1));
        }
        else
        {
            M[str[i]]++;
        }
        a[i]=M[str[i]];
    }
    sort(begin(arr),end(arr),greater<>());
    for(int i=0;i<arr.length();i++)
    {
    	while(arr[i]>0)
    	{
    		
	}
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	 	string S;
		getline(S,cin);
		printFrequency(S);	 	
	}


	return 0;
}


