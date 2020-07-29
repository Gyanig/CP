#include <bits/stdc++.h>

using namespace std;

int main(){
	cout << "Selection Sort \n";
	int a[5];
	cout << "Enter 5 numbers to sort \n";
	for(int i=0;i<5;i++)
		cin >> a[i];
	
	for(int i=0;i<5;i++)
		cout << a[i] << "\t";
		
	cout << "\n";
		
	for(int i=0;i<5;i++)
	{
		int min=i;
		
		for(int j=i+1;j<5;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			cout << a[i] << "\t" << a[min] << "\n";
			int temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}

	}
	
	for(int i=0;i<5;i++)
	{
		cout <<a[i] <<"\t";
	}
	return 0;
}
