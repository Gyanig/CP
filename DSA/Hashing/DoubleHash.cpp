#include<bits/stdc++.h>
using namespace std;
#define TABLE_SIZE 13
#define prime 19

class DoubleHash{
    int size;
    int *table;
    
    public:
        DoubleHash()
        {
            table= new int[TABLE_SIZE];
            size=0;
            for(int i=0;i<TABLE_SIZE; i++)  table[i]=-1;
        }
        bool isFull() { return (size ==TABLE_SIZE); }
        int hash1(int x){return (x%TABLE_SIZE);}
        int hash2(int x){return (prime - (x%prime));}

        void insertItem(int x)
        {
            if(isFull()) return;
            int index1=hash1(x);
            if(table[index1]!=-1)
            {
                int index2=hash2(x);
                int i=1;
                while(1)
                {
                    int newIndex=(index1 + i*index2)%TABLE_SIZE;
                    if(table[newIndex] == -1)
                    {
                        table[newIndex] = x;
                        break;
                    }
                    i++;
                }
            }
            else
                table[index1] = x;
            size++;    
        }

        void Search(int x)
        {
            int index1=hash1(x);
            int index2=hash2(x);
            int i=0;
            while(table[(index1 + i*index2)%TABLE_SIZE]!=x)
            {
                if(table[(index1 + i*index2)%TABLE_SIZE]==-1)
                {
                    cout<<"Not present"<<endl;
                    return;
                }
                i++;
            }
            cout<<x<<" present"<<endl;
        }

        void displayHash()
        {
            for(int i=0; i<TABLE_SIZE; i++)
            {
                if(table[i]!=-1)
                    cout<<i<<" --> "<<table[i]<<endl;
                else
                    cout<<i<<endl;
            }
        }
};


int main()
{
    int a[] = {15, 11, 27, 8, 12,5, 14, 6};
    int n = sizeof(a)/sizeof(a[0]);
    DoubleHash h; 
    for (int i = 0; i < n; i++) 
        h.insertItem(a[i]);

    h.Search(12);
    h.Search(9);
    h.displayHash();
    return 0;
}