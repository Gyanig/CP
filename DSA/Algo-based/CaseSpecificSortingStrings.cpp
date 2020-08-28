//Input: str = “gEeksfOrgEEkS”
//Output: eEfggkEkrEOsS
//
//Input: str = “eDefSR”
//Output: eDefRS

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1;
	s1="GyaNigKumArIsgrEaT";
	cout<<s1<<endl;
	int n=s1.length();
	
	vector<char> v1,v2;
	
	for(int i=0;i<n;i++)
	{
		if(s1[i]>='a' && s1[i]<='z')
			v1.push_back(s1[i]);
		if(s1[i]>='A' && s1[i]<='Z')
			v2.push_back(s1[i]);	
	}
	
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	
	int i=0,j=0;
	
	for(int k=0;k<n;k++)
	{
		if(s1[k]>='a'&& s1[k]<='z')
		{
			s1[k]=v1[i];
			i++;
		}
		if(s1[k]>='A'&& s1[k]<='Z')
		{
			s1[k]=v2[j];
			j++;
		}
	}
	
	cout<<s1<<endl;
	
	
	
	return 0;
}
