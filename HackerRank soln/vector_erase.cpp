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
    
    int x;
    cin>>x;
    a.erase(a.begin()+x-1);
//    cout<<"hello"<<endl;
    int t1,t2;
    cin>>t1>>t2;
    a.erase(a.begin()+t1,a.begin()+t2);
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
        
    }
    cout<<endl;
    return 0;
}


 


