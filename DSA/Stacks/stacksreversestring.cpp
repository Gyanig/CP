//using stl::stack as template

//using for string
#include <bits/stdc++.h> 
using namespace std; 
   
int main () 
{ 
    stack <char> s; 
    string input="Hello World";
    string output="";
    
    int l=input.length();
    
    for(int i=0;i<l;i++)
    {
    	char c=input[i];
    	s.push(c);
	}
	
	for(int i=0;i<l;i++)
	{
		cout<<s.top();
		if(!s.empty())
			s.pop();
	}
	cout<<endl;
  
    return 0; 
} 
