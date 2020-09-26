#include<bits/stdc++.h>
using namespace std;

int prec(char op)
{
	switch(op)
	{
		case '^': return 3;
		case '*': return 2;
		case '/': return 2;
		case '+': return 1;
		case '-': return 1;
		default:return -1;				
	}
}


// passing input
void infix_postfix(string t)
{
	std::stack<char> exp; //using the stack for char stack
	exp.push('T');  // setting top element as T for stack
	int l=t.length(); // length of expression
	string out;
	
	//works without the parenthesis
	for(int i=0;i<l;i++)
	{
		if((t[i]>='a' && t[i]<='z')|| (t[i]>='A') && (t[i]<='Z'))
			out+=t[i];
		
		//left parenthesis
		else if(t[i]=='(')
			exp.push('(');
			
		// If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 	
		else if(t[i]==')')
		{
			while(exp.top()!='T'&& exp.top()!='(')
			{
				char c=exp.top();
				exp.pop();
				out+=c;
			}
			if(exp.top()=='(')
			{
				char c=exp.top();
				exp.pop();
			}	
		}	
		
		else
		{
			while(exp.top()!='T' && prec(t[i])<= prec(exp.top()))
			{
				char c=exp.top();
				exp.pop();
				out+=c;
			}
			exp.push(t[i]);	
		}		
	}
	
	while(exp.top() !='T')
	{
		char c=exp.top();
		exp.pop();
		out+=c;
	}
	
	cout<<out<<endl;
	
}

int main()
{
	string exp="(p+q*r^s)/(p+q^s)";
	cout<<exp<<endl;
	infix_postfix(exp);
	
	return 0;
}
