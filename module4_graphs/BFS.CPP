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
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (auto i = adj[u].begin(); i != adj[u].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }
};  
int main()
{

    return 0;
}
