#include<bits/stdc++.h>
using namespace std;

struct n{
	int a;
	string b;
	string c;
};

int main()
{
	vector<n> p5;
	n test;
	test.a=1;
	test.b="Hello World!";
	test.c="Hello indeed!";
	p5.push_back(test);
	cout<<test.a<<" "<<test.b<<" "<<test.c<<endl;
	cout<<p5[0].a<<endl;
	return 0;
}


	
