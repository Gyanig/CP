//postfix evaluation


#include<bits/stdc++.h>
using namespace std;

void evalpostfix(string a)
{
	string f="";
	std::stack<string> s;
	// i have use () to seperate the smaller operations 
	cout<< a<<endl;
	s.push("T");
	int l=a.length();
//	cout<<l<<endl;
	for(int i=0;i<l;i++)
	{
//		cout<<a[i]<<"-current, i= "<<i<<endl;
		
		if((a[i]>='a') && (a[i]<='z'))
		{
//			cout<<"check 1"<<endl;
			char c=a[i];
			string pp="";
			pp+=c;
			s.push(pp);
			cout<<s.top()<<endl;
		}
		
		else
		{
//			cout<<"check 2"<<endl;
			string x=s.top();
			s.pop();
			string y=s.top();
			s.pop();
			f="";
			f+="(";
			f+=x;
			f+=a[i];
			f+=y;
			f+=")";
			cout<<f<<endl;
			s.push(f);
		}
		
	}
	cout<<s.top()<<endl;
	
}



int main()
{
	string exp="abc/+de*-+f";
	evalpostfix(exp);
	return 0;
}
