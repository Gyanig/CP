#include<bits/stdc++.h>
using namespace std;


int main(){
	double seven=7;
	unsigned long long int K;
	cin>>K;
	if(K%2==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	bool flag=true;
	double count=0;
	while(flag){
		count++;
		if(seven%K==0){
			flag=false;
		}
		seven=seven*10+seven;
	}
	
	cout<<(int)count<<endl;
	return 0;
}
