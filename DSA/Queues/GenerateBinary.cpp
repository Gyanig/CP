#include<bits/stdc++.h>
using namespace std;
// O(n*log n)
void GenerateBinary(int n)
{
	queue<string> q;
	q.push("1");
	
	while(n--)
	{
		cout<<n<<":"<<endl;
		string s1=q.front();
		q.pop();
		cout<<s1<<endl;
		
		string s2=s1;

		q.push(s1.append("0"));
		cout<<q.front()<<" ";
		q.push(s2.append("1"));
		cout<<q.front()<<endl<<endl;
		
	}
	
	
}

int main()
{
	int n;
	cin>>n;
	GenerateBinary(n);
	return 0;
}
