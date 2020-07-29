#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int* x,int *y){

	int temp = *x;
	*x=*y;
	*y=temp;

}

void fun(int n, int* square,double *sq_root){
	*square =n*n;
	*sq_root= sqrt(n);
}

int* CreateArray(int n){
	return new int[n];
}

int main(){
	int var=10;
	int*ptr=&var;
	cout << *ptr <<endl;
	
	cout << ptr <<endl;
	*ptr=20;
	
	cout << *ptr <<endl;
	
	int v[3]={10,20,30};
	ptr=v;
	for(int i=0;i<3;i++){
		cout << *ptr <<endl;
		cout<< ptr <<endl;
		cout << ptr[i] <<endl;
	}
	
	cout<<"\nSwap\n";
	int a=99,b=999;
	
	swap(&a,&b);
	cout << a << " "<< b<<endl;
	
	cout << "Return\n";
	int n=100;
	int* sq=new int;
	double* sq_root= new double;
	fun(n,sq,sq_root);
	cout << *sq <<" "<< *sq_root << endl;
	
	int* pft =CreateArray(10);
	cout << *ptr << endl;
	
	cout << "References \n" << endl;
	//Initialization
	
	int f=10;
	//int *l=&f;
	// cout << *l <<endl; - 10
	
	int &l=f;   // it is not a pointer, it saves a value at the memory address l
	cout << l <<endl; //doesnt take *l;
		
	//reassignment
	
	a=5;
	b=6;
	ptr =&a;
	
	//memory address
	int &pkt=a;
	cout << &(&pkt) <<endl;
	//NULL value
	//Indirection
	
	a=10;
	int *o
	//Arithmetic operations 
	
	
	return 0;
}
