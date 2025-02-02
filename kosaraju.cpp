#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}
void reverseDfs(int node, vector<vector<int>> &transpose, vector<bool> &visited, vector<int> &scc) {
    visited[node] = true;
    scc.push_back(node);
    for (int neighbor : transpose[node]) {
        if (!visited[neighbor]) {
            reverseDfs(neighbor, transpose, visited, scc);
        }
    }
}
void kosaraju(int V, vector<vector<int>> &adj) {
    stack<int> st;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    vector<vector<int>> transpose(V);
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            transpose[neighbor].push_back(i);
        }
    }
    fill(visited.begin(), visited.end(), false);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            vector<int> scc;
            reverseDfs(node, transpose, visited, scc);

            // Print the SCC
            cout << "SCC: ";
            for (int vertex : scc) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
}
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj(V);
    cout << "Enter the edges (u v) where u -> v:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << "Strongly Connected Components:" << endl;
    kosaraju(V, adj);
    return 0;
}
