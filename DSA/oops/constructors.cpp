#include<bits/stdc++.h>
using namespace std;

class num{
	private:
		int a,b;
	
	public:
		//default constructor
		num()
		{
			a=10;
			b=20;
		}
		
		//parametertized constructor
		num(int x,int y)
		{
			a=x;
			b=y;
		}
		
		//copy constructor
		num(num &j){
			
			a=j.a;
			b=j.b;
		}
		
		void show()
		{
			cout<<"Values are :"<<a<<" "<<b<<endl;
		}
};

int main(){
	num ob1;
	num ob2(50,100);
	num ob3(ob2);
	num ob4=ob1; //copy constrcutor
	
	ob1.show();
	ob2.show();
	ob3.show();
	ob4.show();
}
