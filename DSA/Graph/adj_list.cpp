#include<iostream>
#include<vector>

using namespace std;

void insert(vector<int> graph[],int u,int v) 
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(vector<int> graph[], int V)
{
    for(int i=0;i<V;i++)
    {
        cout<<i<<" : ";
        for(auto j:graph[i])
            cout<<" -> "<<j;
        cout<<endl;
    }
}

int main()
{
    int V=5;
    vector<int> graph[V];
    insert(graph,0,1); 
    insert(graph, 0, 4);
    insert(graph, 1, 2);
    insert(graph, 1, 3);
    insert(graph, 1, 4);
    insert(graph, 2, 3);
    insert(graph, 3, 4);
    printGraph(graph, V);
    return 0;
}