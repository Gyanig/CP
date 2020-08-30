#include <bits/stdc++.h> 
using namespace std; 
  
bool balanced(string exp) 
{ 
	stack <char> s;
	char x;
	
	for(int i=0;i<exp.length();i++)
	{
		//store front facing parenthesis 
		if(exp[i]=='(' ||exp[i]=='['|| exp[i]=='{')
		{
			s.push(exp[i]);
			continue;
		}
		
		//if already empty return false
		if(s.empty())
		{
			return false;
		}
		
		//check for each parenthesis cases
		switch (exp[i]) { 
	        case ')': 
	            x = s.top(); 
	            s.pop(); 
	            if (x == '{' || x == '[') 
	                return false; 
	            break; 
	  
	        case '}': 
	            x = s.top(); 
	            s.pop(); 
	            if (x == '(' || x == '[') 
	                return false; 
	            break; 
	  
	        case ']': 
	            x = s.top(); 
	            s.pop(); 
	            if (x == '(' || x == '{') 
	                return false; 
	            break; 
        } 
    } 
	
	return (s.empty());	
} 
  
int main () 
{ 
    stack <char> s; 
	
	cout<<"Enter inputs:"<<endl;
	string a="";
	getline(cin,a);
	cout<<a;
	
	bool t=balanced(a);
	
	if(t==true)
		cout<<" is Balanced!"<<endl;
	else
		cout<<"is not Balanced!"<<endl;
	
    return 0; 
} 
