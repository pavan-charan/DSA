#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &recStack, stack<int> &topoStack) {
    visited[node] = 1;        
    recStack[node] = 1;       

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack, topoStack)) {
                return true;  
            }
        } else if (recStack[neighbor]) {
            return true;      
        }
    }

    recStack[node] = 0;      
    topoStack.push(node);    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> visited(n, 0);
    vector<int> recStack(n, 0);
    stack<int> topoStack;

    bool cycleDetected = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack, topoStack)) {
                cycleDetected = true;
                break;
            }
        }
    }

    if (cycleDetected) {
        cout << "Cycle Detected" << endl;
    } else {
        cout << "No Cycle Detected" << endl;
        cout << "Topological Order: ";
        while (!topoStack.empty()) {
            cout << topoStack.top() << " ";
            topoStack.pop();
        }
        cout << endl;
    }

    return 0;
}
