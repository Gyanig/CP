#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << "Insertion Sort \n";
	int a[8];
	cout << "Enter 8 numbers to sort \n";
	for(int i=0;i<8;i++)
		cin >> a[i];
	
	for(int i=0;i<8;i++)
		cout << a[i] << "\t";
		
	cout << "\n";
	int j,pos;	
	for(int i=1;i<8;i++)
	{
		pos=a[i];
		j=i-1;
		while(j>=0 && a[j]>pos)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=pos;
	}
	
	for(int i=0;i<8;i++)
	{
		cout <<a[i] <<"\t";
	}
	
	return 0;
}

// sorted array ko shift karte jana after finding the best postion of the number
