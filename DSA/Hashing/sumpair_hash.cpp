#include <bits/stdc++.h>
using namespace std;

bool sumpair(int arr[], int n,int sum)
{
    unordered_set<int> s;
    bool result=false;
    for (int i = 0; i<n; i++)
    {
        int temp = sum - arr[i];
        if (s.find(temp) != s.end())
        {
            if(arr[i]+temp == sum)
                result=true;

            cout<<"Sum : "<<arr[i]<< "+"<<temp<<" = "<<arr[i]+temp<<endl;
        }
        s.insert(arr[i]);
    }
    return result;
}

int main()
{
	int arr[] = { 1, 4, 45, 6, 10, -8 };
	int sum = 11;
	int n = sizeof(arr) / sizeof(arr[0]);

	if (sumpair(arr, n, sum))
		cout<< "found";
	else
		cout<< "not found";

	return 0;
}
