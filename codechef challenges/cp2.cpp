#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		unsigned long int arr[n];
		
		for(int i=0;i<n;i++){
			cin >> arr[i];
			arr[i]=(arr[i] / 100000000);
		}
		
		int result = 0; 
  		int count =0;
    	
    	int subarrlen=(n*(n+1))/2;
    	int subarr[subarrlen];
    	
    	//int result = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = i; j < n; j++) {
				sum += arr[j];
				result += sum;
				cout<< result <<" " <<sum << "\n";
				if(sum==10)
				{
					count++;
				}
			}
		}	


		cout << count;
	}	
	return 0;
}
