#include <iostream>
#include <bits/stdc++.h>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
using namespace std;


int main(){
	int t;
	cin>> t;
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    while(t--){
		string s="";
		getline(cin,s);
		//transform(s.begin(), s.end(), s.begin(), ::tolower); 
		int l=s.length();
		//int j=0;
		int diff1,diff2;
	
		int sum=0;
		
		for(int i=0;i<l;i++)
		{
			int ch=s[i];
			if(ch==32)
				continue;
			ch=ch-96;
			diff1=0;
			diff2=0;
			if(ch>1 && ch <5){
				diff1=abs(ch-1);
				diff2=abs(ch-5);
			}
			else if(ch>5 && ch <9){
				diff1=abs(ch-5);
				diff2=abs(ch-9);
			}
			else if(ch>9 && ch <15){
				diff1=abs(ch-1);
				diff2=abs(ch-5);
			}
			else if(ch>15 && ch<21){
				diff1=abs(ch-15);
				diff2=abs(ch-21);
			}
			
			if(diff1>diff2)
					sum=sum+diff2;
			else
				sum=sum+diff1;
			//cout <<sum <<" " << ch << " " << diff1 << " " << diff2<<endl;
		}
		cout<<sum<<"\n";
		
	}
	
	return 0;
}
