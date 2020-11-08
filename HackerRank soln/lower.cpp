#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        a.push_back(num);
    } 
    int s;
    cin>>s;
    
	int q[s];
	for(int i=0;i<s;i++)
	{
		int in;
		cin>>in;
		q[i]=s;
		vector<int>::iterator l;
		l=lower_bound(a.begin(),a.end(),in);
		if(l!=a.end() && *l==in)
			cout<<"Yes ";
		else
			cout<<"No ";
			
		cout<<(l-a.begin()+1)<<endl;
	}
	
    return 0;
}


 


