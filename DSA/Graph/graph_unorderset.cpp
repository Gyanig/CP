#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    unordered_set<int>* adjList;
    public:
        Graph(int x)
        {
            V=x;
            adjList=new unordered_set<int>[V];
        }
        void addEdge(int v,int e)
        {
            adjList[v].insert(e);
            adjList[e].insert(v);
        }
        void printGraph()
        {
            for(int i=0;i<V;i++)
            {
                unordered_set<int> res=adjList[i];
                cout<<i<<" : ";

                for(auto itr= res.begin();itr!=res.end(); ++itr)
                    cout<<*itr<<" ";
                cout<<endl;
            }
        }
        void search(int v,int e)
        {
            auto itr= adjList[v].find(e);
            if(itr == adjList[v].end()) 
                cout<<v<<"->"<<e<<" : not found"<<endl;
            else
                cout<<v<<"->"<<e<<" : found"<<endl;
        }
};

int main()
{

    int V=5;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
 
    g.search(2, 1);
    g.search(0, 3);
	return 0;
}

