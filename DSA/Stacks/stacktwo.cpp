#include<bits/stdc++.h>
using namespace std;

//two methods are available   :
// 1.	Divide the arr into two halves from middle
// 2.	place the top elements in two extremes ( i prefer this coz it is more efficient )

class stacks{
	int *arr;
	int size;
	int top1;
	int top2;
	public:
		//default constructor
		stacks(int n){
			size=n;
			arr=new int[size];
			top1=-1;
			top2=size;
		}
		
		// fucntions push(),pop(), peek() and empty()
		
		void push1(int data)
		{
			if(top1 < top2-1)
			{
				top1++;
				arr[top1] = data;
				cout<<"pushed 1:"<<data<<endl;
			}
			else{
				cout<<"Stack Overflow "<<"By element :"<<data<<endl;
				return;
			}
		}
		
		void push2(int data)
		{
			if(top1 < top2-1){
				top2--;
				arr[top2]=data;
				cout<<"pushed 2:"<<data<<endl;
			}
			else{
				cout<<"Stack Overflow "<<"By element :"<<data<<endl;
				return;
			}
		}
		
		int pop1()
		{
			if(top1 >= 0)
			{
				int data=arr[top1];
				top1--;
//				cout<<"popped 1"<<endl;
				return data;
				
			}
			else
			{
				cout<<"Stack Underflow"<<endl;
				return 0;
			}
		}
			
		int pop2()
		{
			if(top2<size)
			{
				int data= arr[top2];
				top2++;
//				cout<<"popped 2"<<endl;
				return data;
			}
			else{
				cout<<"Stack Underflow"<<endl;
				return 0;
			}
		}
		
		int peek1()
		{
			if(top1!=-1)
			{
				cout<<arr[top1]<<endl;
				return arr[top1];	
			}
			else
			{
				cout<<"Stack is empty"<<endl;
				return 0;	
			}	
		}
		
		int peek2()
		{
			if(top2!=size)
			{
				cout<<arr[top2]<<endl;
				return arr[top2];	
			}
			else
			{
				cout<<"Stack is empty"<<endl;
				return 0;	
			}	
		}
	
};


int main()
{
	
	stacks s(10);
	
	for(int i=1;i<5;i++)
	{
		s.push1(i*10);
		s.push2(i*20);
	}
	
	int p1=s.pop1();
	int p2=s.pop2();
	cout<<p1<<" "<<p2<<endl;
		
	int k1= s.peek1();
	int k2= s.peek2();
	cout<<k1<<" "<<k2<<endl;
	
}
