#include<bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        n = 4 * n - 1;
        vector<int> x(n), y(n);
        
		for (unsigned long long i = 0; i < n; ++i)
            cin >> x.at(i) >> y.at(i);
            
        //calculate the even no of x values
        //calculate the even no of y values
        int lp= accumulate(x.begin(),x.end(),0L,bit_xor<int>());
        int rp= accumulate(y.begin(), y.end(),0L, bit_xor<int>());
        
		cout << lp << ' ' << rp << '\n';
    }
    
    return 0;
}
