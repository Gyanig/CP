#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<pair<int,int>>* adjList;
    public:
        Graph(int x)
        {
            V=x;
            adjList=new vector<pair<int,int>>[V];
        }
        void addEdge(int v,int u,int wt)
        {
            adjList[v].push_back(make_pair(u,wt));
            adjList[u].push_back(make_pair(v,wt));
        }
        void printGraph()
        {
            int v,w;
            for(int i=0;i<V;i++)
            {
                cout<<i<<" : ";
                for(auto itr= adjList[i].begin();itr!=adjList[i].end(); itr++)
                {
                    v=itr->first;
                    w=itr->second;
                    cout<<v<<"("<<w<<")"<<endl;
                }
                cout<<endl;
            }
        }     
};

int main()
{

    int V=5;
    Graph g(V);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);

    g.printGraph();
    return 0;
}

