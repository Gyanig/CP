//binary heap
#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
class MinHeap{
    public: 
        int * harr;
        int capacity;
        int heap_size;
        MinHeap(int cap)
        {
            heap_size=0;
            capacity=cap;
            harr= new int[cap];
        }

        //basic heap functions
        int parent(int i){return (i-1)/2;}
        int left(int i){return (2*i +1);}
        int right(int i){return (2*i +2);}

        //ADTs
        void insertKey(int key)
        {
            if(heap_size==capacity)
            {
                cout<<"Overflow"<<endl;
                return;
            }
            heap_size++;
            int i=heap_size-1;
            harr[i]= key;
            while(i!=0 && harr[parent(i)]>harr[i])
            {   
                swap(&harr[i],&harr[parent(i)]);
                i=parent(i);
            }
        }

        void decreaseKey(int i,int input)
        {
            harr[i]= input;
            while(i!=0 && harr[parent(i)] >harr[i])
            {
                swap(&harr[i],&harr[parent(i)]);
                i=parent(i);
            }
        }
        
        void MinHeapify(int i)
        {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if (l < heap_size && harr[l] < harr[i])
                smallest = l;
            if (r < heap_size && harr[r] < harr[smallest])
                smallest = r;
            if (smallest != i)
            {
                swap(&harr[i], &harr[smallest]);
                MinHeapify(smallest);
            }
        }  

        int extractMin()
        {
            if(heap_size <=0)
                return INT_MAX;
            if(heap_size==1)
            {
                heap_size--;
                return harr[0];
            }    

            int root= harr[0];
            harr[0]= harr[heap_size-1];
            heap_size--;
            MinHeapify(0);

            return root;
        }

        int getMin() {return harr[0];}

        void deleteKey(int i)
        {
            decreaseKey(i,INT_MIN);
            extractMin();
        }
};

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    // h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    // cout << h.extractMin() << " ";
    // cout << h.getMin() << " ";
    // h.decreaseKey(2, 1);
    // cout << h.getMin();

    h.insertKey(0);
    cout<<endl;
    for(int i=0;i<h.heap_size;i++)
        cout<<h.harr[i]<<" ";

    cout<<endl;    
    return 0;
}