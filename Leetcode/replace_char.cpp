#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while(t--)
	{
		string s="";
//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin,s);
		//prev next
		int l=s.length();
		
		if(l==1)
		{
			s="a";
			cout<<s<<endl;
			continue;
		}
		int i=0;
		char def='a';
		while(i<(l))
		{
			def='a';
			if(s[i]=='?')
			{
				if(i==0)
				{
					char next=s[i+1];
					if(next=='a')
						def++;		
				}
				else
				{
					char prev=s[i-1];
					char next=s[i+1];
					if(prev=='a'&& next=='a')
						def++;
					if(prev=='a' && next =='b')
						def=def+2;
					if(prev=='b' && next=='a')
						def=def+2;
                    if(prev=='a' && next!='b')
                        def++;
                    if(next=='a'&& prev!='b')
                        def++;
				}	
				s[i]=def;	
			}
			i++;
		}
		cout<<s<<"\n";
	}

	
	return 0;
}
