#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1000;

int lookup_table[MAX_SIZE];

void create_table(int n){
	int pow=1;
	int co=0;
	
	do{
		pow<<=1;
		lookup_table[co]=(n+(pow>>1))/pow;
		cout << lookup_table[co] << "\n";
	}while(lookup_table[co++]!=0);
	cout<<"\n";
}

int binary(int arr[],int v){
	//mid-point of array
	int index=lookup_table[0] - 1;
	
	//count
	int co=0;
	
	while(lookup_table[co]!=0)
	{
		if(v==arr[index])
			return index;
			
		else if(v<arr[index])
			index -= lookup_table[++co];
			
		else
			index += lookup_table[++co];
		
		cout<<index<< " "<<arr[index]<< "\t";			
	}
	cout <<"\n";

}

int main(){
	int arr[]={1,3,5,6,7,8,9};
	int n= sizeof(arr)/sizeof(int);	
	
	//create a lookup table
	create_table(n);

	//index of 3=1	
	cout<< binary(arr,9)<<endl;
	
	return 0;	
}
