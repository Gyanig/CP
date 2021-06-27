#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int>* g;
    public:
        Graph(int x)
        {
            V=x;
            g=new list<int>[V];
        }
        void insert(int v,int u)
        {
            g[v].push_back(u);
        }
        //starting node : s
        void bfs(int s)
        {   
            bool *visited = new bool[V];
            for(int i=0;i<V;i++)
                visited[i]=false;

            list<int> trav;
            visited[s]=true;
            trav.push_back(s);

            list<int>::iterator it;

            while(!trav.empty())
            {
                s=trav.front();
                cout<<s<<" ";
                trav.pop_front();
                for(it = g[s].begin();it!=g[s].end();it++)
                {
                    if(!visited[*it])
                    {
                        visited[*it]=true;
                        trav.push_back(*it);
                    }
                } 
            }    

        }
};


int main()
{
    Graph g(4);
    g.insert(0, 1);
    g.insert(0, 2);
    g.insert(1, 2);
    g.insert(2, 0);
    g.insert(2, 3);
    g.insert(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
 
    return 0;
}