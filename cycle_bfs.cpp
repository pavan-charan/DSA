#include <bits/stdc++.h>
using namespace std;

bool kahnAlgorithm(int n, vector<vector<int>> &adj, vector<int> &topologicalOrder) {
    vector<int> inDegree(n, 0);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topologicalOrder.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return topologicalOrder.size() == n;
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

    vector<int> topologicalOrder;

    if (kahnAlgorithm(n, adj, topologicalOrder)) {
        cout << "No Cycle Detected" << endl;
        cout << "Topological Order: ";
        for (int node : topologicalOrder) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "Cycle Detected" << endl;
    }

    return 0;
}
