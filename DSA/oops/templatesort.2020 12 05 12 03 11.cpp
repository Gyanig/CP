#include<iostream>
using namespace std;

template <class T>

void sort(T arr[], int size){
     for (int i = 0; i < size; i++)
     {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                T temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
     }
}


int main(){

    cout<<"Enter the size of the array : ";
    int n;
    cin>>n;
    int int_array[n];
    float float_array[n];
    
    cout<<"Enter integer array elements:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>int_array[i];
    }
    
    
    cout<<"Enter floating array elements:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>float_array[i];
    }
    
    sort(int_array,n);
    sort(float_array, n);
    
    cout<<"After sorting they are :"<<endl;
    
    for (int i = 0; i < n; i++)
    {
        cout<<int_array[i]<<" ";
    }
    cout<<endl;
    
    for (int i = 0; i < n; i++)
    {
        cout<<float_array[i]<<" ";
    }
    
    return 0;
}
