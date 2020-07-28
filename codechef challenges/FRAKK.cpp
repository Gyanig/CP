#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>> t;
	while(t--){

		int arr[1000];
		int count;
		cin >> count;
		int a,b;
		cin >> a ;
		cin >> b ;
		long sum,temp;
		while(a>b){
			temp=a;
			a=a/b;
			temp=temp-(b*a);
		}
		a=temp;
		cout << a << " ";
		while(count>0){
			a=a*10;
			while(a>b){
				temp=a;
				a=a/b;
				temp=temp-(b*a);
			}
			sum=sum+a;
			cout << a << " " << sum << endl;
			a=temp;	
			count--;
		}
		
	}
	return 0;
}
