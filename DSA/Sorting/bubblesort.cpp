#include <bits/stdc++.h>

using namespace std;

int main(){
	cout << "Bubble Sort \n";
	
	int a[5];
	cout << "Enter 5 numbers to sort \n";
	for(int i=0;i<5;i++)
		cin >> a[i];
	
	int flag=0;
	for(int i=0;i<5;i++)
	{	
		flag=0;
		for(int j=0;j<4;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	
	
	for(int i=0;i<5;i++)
	{
		cout <<a[i] <<"\t";
	}
	return 0;	
}
