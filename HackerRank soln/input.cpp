#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
	fstream file; 
    string filename; 
  	string word="";
    filename = "input08.txt"; 
  
    file.open(filename.c_str()); 
  	int n = 0;
  	int k=0;
  	
  	file >> n >> k;
  	cout << n <<" "<<k<<endl;
  	
  	unsigned long int arr[n];
  	unsigned long int l=0;
  	
    while (l<n) 
    {
        file >> arr[l];
//       cout << arr[l] << " ";
        l++;
    } 

    sort(arr,arr+n);
//
//	int arr[]={1,4,5,7,9,10,11};
//	int n=7;
//	int k=2;
    int count=0;
    int pos=0;

	for(long int i=0;i<n;i++)
	    cout << arr[i]<< " ";
//
//     cout<< arr[0];
    for(long int i=arr[0]-1;i<=arr[l-1];i++){
        //cout << i << "\t" << pos <<"\n";
			
        if(i==arr[pos])
        {
            while(arr[pos]==arr[pos+1]){
                pos++;
            }

//          cout << arr[pos]<< "\n";
            if((i+k)>=arr[pos+1])
            {
                count++;
                i=i+(2*k);
                while(arr[pos]<=i){
                    pos++;
                }
                //cout << count  << " " <<arr[pos]<<"\n"; 
            }
            else
            {
                count++;
                pos++;
            }
        }
    }
    
    cout << count <<endl;

    
    return 0;
}
