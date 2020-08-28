#include<bits/stdc++.h>
using namespace std;

class A{
	int c;
	public:
		void add(int a,int b)const
		{
//			c=a+b;
			a+b;
			cout<<"Sum"<<a+b<<endl;
		}
};


int main(){
	
	A ob;
	ob.add(10,25);
	return 0;
}
