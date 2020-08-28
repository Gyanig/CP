#include<bits/stdc++.h>
using namespace std;

class kstack{
	int ksize,size;
	int k;
	int *top;
	int *arr;
	public:
		kstack(int k,int n){
			size=n;
			ksize=k*n;
			arr=new int[size];
			top=new int[k];
			
			
			for (int i = 0; i < k; i++) 
        	{
        		arr[i*k+1]=0;
				top[i] = -1;
        	}
		}
		
		void push(int data,int k);
		int pop(int k);
		int peek(int k);
		bool empty(int k);
};

void kstack::push(int data,int ki)
{
	if(top[ki]>size)
	{
		cout<<ki<<"the stack overflow";
		return;
	}
	
	else{
		//last element entered is at index top[ki] : ki is just stack number
		
	}
}


int main()
{
	
	
}
