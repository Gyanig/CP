#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int Search(vector<int>& arr,int find,int flag)
    {
        int low =0;
        int high=arr.size();
        
        while(low<high)
        {
            int mid= (low+high)/2;
            if((find<arr[mid]) || (find==arr[mid] && flag==0))
            {
                high=mid;
            }
            else
            {
               low=mid+1;
            }      
        }
        
        return low;
    }
    
    vector<int> searchRange(vector<int>& arr, int target) {
       
        vector<int> output;
        output.push_back(-1);
        output.push_back(-1);
       
        int left=Search(arr,target,0);
        
        if( (left==arr.size()) || (arr[left] != target) ){
            return output;
        }
        
        int right= Search(arr,target,1) - 1;
        
        vector<int> finaloutput;
        finaloutput.push_back(left);
        finaloutput.push_back(right);
            
        return finaloutput;
            
    }
};
