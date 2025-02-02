#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void bfs(vector<vector<int>>& adj, int s) {
    queue<int> q;  
    vector<bool> visited(adj.size(), false);
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        cout << c << " ";

        for (int x : adj[c]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    vector<vector<int>> adj(V);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    int start;
    cout << "Enter the starting vertex for BFS: ";
    cin >> start;
    cout << "BFS starting from " << start << " : \n";
    bfs(adj, start);
    return 0;
}
