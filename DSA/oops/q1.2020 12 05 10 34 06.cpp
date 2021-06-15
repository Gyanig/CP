#include<bits/stdc++.h>
using namespace std;

class base
{
 int x;
    public:

 	  base(int a)
    	  {
		x=a;
		}

	 void display()
	{
	 cout<<x<<"\n";
	}

};

class derived : public base
{
  int d;
  public:
	  derived(int a, int b): base(a)
	  {
	    d=b;
	    }
	void display()
	{

	   cout<<d;
	}

};

int main()
{

 derived D(10,20);
 D.base::display();
 D.display();
 return 0;

}
