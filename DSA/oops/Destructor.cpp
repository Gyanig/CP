//~ used for destructor
//no default values nor overloaded
//calls delete operator(internally) implicitily

#include<bits/stdc++.h>
using namespace std;

class Employee{
	public:
		Employee()
		{
			cout<<"Hello"<<endl;
		}
		
		~Employee()
		{
			cout<<"Destructor"<<endl;
		}
};

int main(void)
{
	Employee e1;
	Employee(); // orphan object as it has no name. But destructor is called immediately
	Employee();
	
	Employee e2;
	//now destructor is called for e2 and then e1 (reverse)
	e1.Employee::~Employee(); // even if it is explicitily callled, it is not deleted from stack
							 // it is deleted at the end also
	
	Employee e3;
	
	Employee e4; 
	{
		Employee e5;
	} // destrutor is invoked due to scope of e5
	Employee e6; 
	return 0;
	
}
