#include<bits/stdc++.h>
using namespace std;

class p{
	public:
		virtual void print()
		{
			cout<<"A"<<endl;
		}
};
class q: public p{
	public:
		void print()
		{
			cout<<"B"<<endl;
		}
};

int main()
{
	p* b=new q;
	b->print();
	return 0;
}

