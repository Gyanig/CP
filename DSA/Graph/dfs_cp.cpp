#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> g[], int u, int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}

void DFSUtil(int u, vector<int> g[],vector<bool> &visited)
{
	visited[u] = true;
	cout << u << " ";
	for (int i=0; i<g[u].size(); i++)
		if (visited[g[u][i]] == false)
			DFSUtil(g[u][i], g, visited);
}

void DFS(vector<int> g[], int V)
{
	vector<bool> visited(V, false);
	for (int u=0; u<V; u++)
		if (visited[u] == false)
			DFSUtil(u, g, visited);
}

int main()
{
	int V = 5;
	vector<int> g[V];

	insert(g, 0, 1);
	insert(g, 0, 4);
	insert(g, 1, 2);
	insert(g, 1, 3);
	insert(g, 1, 4);
	insert(g, 2, 3);
	insert(g, 3, 4);
	DFS(g, V);
	return 0;
}
