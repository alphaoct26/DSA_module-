// Write a CPP program to determine whether the graph is connected or not using BFS traversals.

// FIRST CREATING PROPER GRAPH

#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    vector<list<int>> adj;

public:
    Graph(int v)
    {
        this->V = v;
        adj.resize(V);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    };
   void BFS(int s)
{
    vector<bool> visited(V, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);

    int count = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        count++; 

        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }

    
    if (count == V)
        cout << "The graph is connected";
    else
        cout << "The graph is not connected";
}
};
int main()
{

    Graph g(4);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}