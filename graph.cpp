//for template
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
    void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}
void Graph::BFS(int s)
{
    
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
    }
}
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input1.txt", "r", stdin);
    freopen ("output1.txt", "w", stdout);
#endif

    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        cout<<i<<" ";
    }
}
