#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//<tag-name attribute1-name = "value1" 
	//      attribute2-name = "value2" ...>
//	<tag1 value = "value">
//	<tag2 name = "name">
//	<tag3 another="another" final="final">
//	</tag3>
//	</tag2>
//	</tag1>

struct set1{
	int a;
	string b;
	string c;
};
	
int main() {
    int p,q;
    cin>>p>>q;
    vector <string> k;
    cin.ignore();
    for(int i=0;i<p;i++)
    {
    	string s;
    	getline(cin,s);
    	k.push_back(s);
	}
	
	vector<string> j;
	for(int i=0;i<q;i++)
	{
		string ss;
		getline(cin,ss);
		j.push_back(ss);
	}
	
	vector<pair<int,string>> tags; // tag names
	vector<pair<string,string>> atr; // attributes of each tag
	vector<pair<int,int> >tagatr; //linking the index of tags-atr
	vector<pair<int,string>> idatr; //id + atr_name
	vector<set1> p5;
	int count=1;
	for(int i=0;i<p/2;i++)
	{
		string str=k[i]; //each string
		string tag_name="";
		pair<int,string> p1;
		pair<string,string> p2;
		pair<int,int> p3;
		pair<int,string> p4;
		// ignore < and >
		int l=str.length();
		
		for(int dx=1;dx<l-1;dx++)
		{
			char check=str[dx];
			while(check!=' ') //extract tag_name and give it a index
			{
				check=str[dx];
				tag_name=tag_name+check;
				dx++;
			}
			p1.first=count;
			count++;
			p1.second=tag_name;
			tags.push_back(p1);
			int c2=0; //counting atr
			while(dx<l-1)
			{
				string attr_name="";
				string attr_value="";
//				dx++;
				check=str[dx];
				while(check!='=') //extract tag_name and give it a index
				{
					check=str[dx];
					if(check!=' ' && check!='=')
						attr_name=attr_name+check;
					dx++;
				}
				
				while(check!='"')
				{
					check=str[dx];
					dx++;
				}
//				dx++;
				check=str[dx];
				while(check!='"')
				{
					check=str[dx];
					if(check!='"')
						attr_value=attr_value+check;
					dx++;
				}
				p2.first=attr_name;
				p2.second=attr_value;
				atr.push_back(p2);
				p4.first=i+1;
				p4.second=attr_name;
				idatr.push_back(p4);
//				dx++;
				c2++;
				set1 test;
				test.a=i+1;
				test.b=attr_name;
				test.c=attr_value;
				p5.push_back(test);
			}
			p3.second=c2;	
		}
		p3.first=p1.first;
		tagatr.push_back(p3);
	}
	
//	cout<<"tags"<<endl;
//	for(int dd=0;dd<tags.size();dd++)
//	{
//		cout<<tags[dd].first<<" "<<tags[dd].second<<endl;
//	}
//	cout<<endl<<"atr"<<endl;
//	for(int dd=0;dd<atr.size();dd++)
//	{
//		cout<<atr[dd].first<<" "<<atr[dd].second<<endl;
//	}
//	cout<<endl<<"tagatr"<<endl;
//	for(int dd=0;dd<tagatr.size();dd++)
//	{
//		cout<<tagatr[dd].first<<" "<<tagatr[dd].second<<endl;
//	}
//	cout<<endl<<"idatr"<<endl;
//	for(int dd=0;dd<idatr.size();dd++)
//	{
//		cout<<idatr[dd].first<<" "<<idatr[dd].second<<endl;
//	}
////	
	//queries
//	tag1~value            "value"
//	tag1.tag2.tag3~name   "Not Found!"
//	tag1.tag2.tag3~final  "final"
	
	vector<string> tt;//store the tags calls in sequences
	vector<string> v1;
	string v;
	vector<pair<int,int>> qq;
	vector<pair<int,string>> idvalue;
	pair<int,int> p1; // storing value with index count for each		  //point to the specifics
	//p1.first-  id , count
	pair<int,string>v2; //id value 
	for(int i=0;i<q;i++)
	{
		int count=0;
		string ss=j[i];
		char check;
		int l= ss.length();
		p1.first=i;
		
		for(int i=0;i<l;i++)
		{
			check=ss[i];
			string ts="";
			while(check!='~')
			{
				check=ss[i];
				char next=ss[i+1];
				if(check!='.')
					ts=ts+check;
				if(next=='~' || check=='.')
				{
					tt.push_back(ts);
					count++;
					ts="";
				}
				i++;
			}
//			i++;
			while(i<l)
			{
				check=ss[i];
				v=v+check;
				i++;
			}
		}
		p1.second=count;
		v1.push_back(v);
		qq.push_back(p1);
		v2.first=i;
		v2.second=v;
		v="";
		idvalue.push_back(v2);
	}
//	
//	cout<<"Queries"<<endl;
//	cout<<endl<<"tt"<<endl;
//	for(int dd=0;dd<tt.size();dd++)
//	{
//		cout<<tt[dd]<<endl;
//	}
//	cout<<endl<<"v1"<<endl;
//	for(int dd=0;dd<v1.size();dd++)
//	{
//		cout<<v1[dd]<<endl;
//	}
//	cout<<endl<<"qq"<<endl;
//	for(int dd=0;dd<qq.size();dd++)
//	{
//		cout<<qq[dd].first<<" "<<qq[dd].second<<endl;
//	}
//	
//	cout<<endl<<"idvalue"<<endl;
//	for(int dd=0;dd<idvalue.size();dd++)
//	{
//		cout<<idvalue[dd].first<<" "<<idvalue[dd].second<<endl;
//	}
	
//	for(int i=0;i<p;i++)
//	{
//		cout<<k[i]<<endl;
//	}
//	
//	for(int i=0;i<q;i++)
//	{
//		cout<<j[i]<<endl;
//	}
//	cout<<"p5"<<endl;
//	for(int il=0;il<p5.size();il++)
//	{
//		cout<<p5[il].a<<" "<<p5[il].b<<" "<<p5[il].c<<endl;
//	}
//	cout<<endl<<endl;
	//printing values 
	for(int ia=0;ia<idvalue.size();ia++)
	{	
		string input=idvalue[ia].second;     // input=name
		int id=qq[ia].second;
//		cout<<input<<" "<<id<<endl;
		int flag=-1;
		string output="";
		
		for(int ic=0;ic<p5.size();ic++)
		{
			if(p5[ic].a>id)
			{
				break;
			}
			if(p5[ic].a==id)
			{
//				cout<<p5[ic].b<<" "<<input<<endl;
				if((p5[ic].b).compare(input)==0)
				{
					flag=1;
					output=output+p5[ic].c;
				}
			}
		}
	
		if(flag==-1)
		{
			cout<<"Not Found!"<<endl;
		}
		else
		{
			cout<<output<<endl;
			output="";
		}
		
	}
	
    return 0;
}

