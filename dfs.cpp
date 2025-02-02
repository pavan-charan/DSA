#include <bits/stdc++.h>
using namespace std;
void dfsrecurssion(vector<vector<int>> &adj, vector<bool> &visited, int s) {
    visited[s] = true;
    cout << s << " ";
    for (int i : adj[s]) {
        if (!visited[i]) {
            dfsrecurssion(adj, visited, i);
        }
    }
}
void DFS(vector<vector<int>> &adj, int s) {
    vector<bool> visited(adj.size(), false);
    dfsrecurssion(adj, visited, s);
}
void addEdge(vector<vector<int>> &adj, int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>> adj(V);
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    int s;
    cout << "Enter the starting vertex for DFS: ";
    cin >> s;
    cout << "DFS from source: " << s << endl;
    DFS(adj, s); 
    return 0;
}
