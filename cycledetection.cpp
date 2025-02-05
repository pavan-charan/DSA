#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int numVertices;
    vector<vector<int>> adjLists;
    vector<bool> visited;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists.resize(vertices);
        visited.resize(vertices, false);
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src); 
    }

    bool bfsCycleDetection(int startVertex) {
        queue<pair<int, int>> q;
        visited[startVertex] = true;
        q.push({startVertex, -1});

        while (!q.empty()) {
            int currentVertex = q.front().first;
            int parentVertex = q.front().second;
            q.pop();

            for (int adjVertex : adjLists[currentVertex]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push({adjVertex, currentVertex});
                } else if (adjVertex != parentVertex) {
                    return true; 
                }
            }
        }
        return false;
    }

    bool detectCycle() {
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                if (bfsCycleDetection(i)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    int src, dest;
    for (int i = 0; i < edges; i++) {
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    if (graph.detectCycle()) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph doesn't contain a cycle." << endl;
    }

    return 0;
}
