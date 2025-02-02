// // #include<bits/stdc++.h>
// // using namespace std;

// // class Edge {
// // public:
// //     int u, v, weight;
// //     Edge(int u, int v, int weight) {
// //         this->u = u;
// //         this->v = v;
// //         this->weight = weight;
// //     }
// // };

// // class Graph {
// // public:
// //     int vertices, edges;
// //     vector<Edge> edge_list;

// //     Graph(int vertices, int edges) {
// //         this->vertices = vertices;
// //         this->edges = edges;
// //     }

// //     void add_edge(int u, int v, int weight) {
// //         edge_list.push_back(Edge(u, v, weight));
// //     }

// //     void find_negative_cycle(int source) {
// //         vector<int> dist(vertices + 1, numeric_limits<int>::max());
// //         vector<int> parent(vertices + 1, -1);

// //         dist[source] = 0;

// //         // Relax all edges V-1 times
// //         for (int i = 1; i <= vertices - 1; ++i) {
// //             for (const Edge& edge : edge_list) {
// //                 if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]) {
// //                     dist[edge.v] = dist[edge.u] + edge.weight;
// //                     parent[edge.v] = edge.u;
// //                 }
// //             }
// //         }

// //         // Check for negative-weight cycles
// //         int cycle_start = -1;
// //         for (const Edge& edge : edge_list) {
// //             if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]) {
// //                 cycle_start = edge.v;
// //                 // To detect the start of the cycle
// //                 for (int i = 0; i < vertices; ++i) {
// //                     cycle_start = parent[cycle_start];
// //                 }

// //                 // Reconstruct the cycle
// //                 vector<int> cycle;
// //                 int current = cycle_start;
// //                 do {
// //                     cycle.push_back(current);
// //                     current = parent[current];
// //                 } while (current != cycle_start);
// //                 cycle.push_back(cycle_start);
// //                 reverse(cycle.begin(), cycle.end());

// //                 // // Print the cycle
// //                 // cout << "Negative weight cycle: ";
// //                 // for (int v : cycle) {
// //                 //     cout << v;
// //                 // }
// //                 cout << "Negative weight cycle: ";
// //                 for (size_t i = 0; i < cycle.size() - 1; ++i) {
// //                     cout << cycle[i];
// //                 }
// //                 cout << endl;
// //                 return;
// //             }
// //         }

// //         cout << "No negative weight cycle" << endl;
// //     }
// // };

// // int main() {
// //     int vertices, edges, source;
// //     cout << "Enter number of vertices: ";
// //     cin >> vertices;
// //     cout << "Enter number of edges: ";
// //     cin >> edges;
// //     cout << "Enter source vertex: ";
// //     cin >> source;

// //     Graph g(vertices, edges);

// //     cout << "Enter edges (from, to, weight):\n";
// //     for (int i = 0; i < edges; ++i) {
// //         int u, v, weight;
// //         cin >> u >> v >> weight;
// //         g.add_edge(u, v, weight);
// //     }

// //     g.find_negative_cycle(source);

// //     return 0;
// // }
// #include<bits/stdc++.h>
// using namespace std;
// class Edge{
//     public:
//     int u,v,weight;
//     Edge(int u,int v,int weight){
//         this->u=u;
//         this->v=v;
//         this->weight;
//     }
// };
// class graph{
// public:
//         int ver,edge;
//         vector<Edge> edgelist;
//         graph(int ver,int edge){
//             this->ver=ver;
//             this->edge=edge;
//         }
//         void addedge(int u,int v,int weight){
//             edgelist.push_back(Edge(u,v,weight));
//         }
//         void negativeO(int src){
//             vector<int> dist(ver+1,numeric_limits<int>::max());
//             vector<int> parent(ver+1,-1);
//             dist[src]=0;
//             for(int i=1;i<=ver-1;i++){
//                 for(const Edge&edge:edgelist){
//                     if(dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]){
//                         dist[edge.u]!=dist[edge.u]+edge.weight;
//                         parent[edge.v]=edge.u;
//                     }
//                 }
//             }
//             int cycsrt=-1;
//             for(const Edge& edge:edgelist){
//                 if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]) {
//                 cycsrt = edge.v;
//                 for (int i = 0; i < ver; i++) {
//                     cycsrt = parent[cycsrt];
//                 }
//                 vector<int> cycle;
//                 int current = cycsrt;
//                 do {
//                     cycle.push_back(current);
//                     current = parent[current];
//                 } while (current != cycsrt);
//                 cycle.push_back(cycsrt);
//                 reverse(cycle.begin(), cycle.end());
//                 cout << "Negative weight cycle: ";
//                 for (size_t i = 0; i < cycle.size() - 1; i++) {
//                     cout << cycle[i];
//                 }
//                 return;
//             }
//         }
//         cout<<"No cycle";
//     }
        
// };
// int main() {
//     int vertices, edges, source;
//     cin >> vertices;
//     cin >> edges;
//     cin >> source;

//     graph g(vertices, edges);

//     for (int i = 0; i < edges; ++i) {
//         int u, v, weight;
//         cin >> u >> v >> weight;
//         g.addedge(u, v, weight);
//     }

//     g.negativeO(source);

//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// class Edge{
// public:
//     int u,v,weight;
//     Edge(int u,int v,int weight){
//         this->u=u;
//         this->v=v;
//         this->weight=weight;
//     }
// };
// class graph{
// public:
//     int ver,edge;
//     vector<Edge> edgelist;
//     graph(int ver,int edge){
//         this->ver=ver;
//         this->edge=edge;
//     }
//     void addedge(int u,int v,int weight){
//         edgelist.push_back(Edge(u,v,weight));
//     }
//     void negativeO(int src){
//         vector<int> dist(ver+1,numeric_limits<int>::max());
//         vector<int> parent(ver+1,-1);
//         dist[src]=0;
//         for(int i=1;i<=ver-1;++i){
//             for(const Edge& edge : edgelist){
//                 if(dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]){
//                     dist[edge.u]=dist[edge.u]+edge.weight;
//                     parent[edge.v]=edge.u;
//                 }
//             }
//         }
//         int cycsrt=-1;
//         for(const Edge& edge:edgelist){
//             if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]) {
//                 cycsrt = edge.v;
//                 for (int i = 0; i < ver; ++i) {
//                     cycsrt = parent[cycsrt];
//                 }
//                 vector<int> cycle;
//                 int current = cycsrt;
//                 do {
//                     cycle.push_back(current);
//                     current = parent[current];
//                 } while (current != cycsrt);
//                 cycle.push_back(cycsrt);
//                 reverse(cycle.begin(), cycle.end());
//                 cout << "Negative weight cycle: ";
//                 for (size_t i = 0; i < cycle.size() - 1; ++i) {
//                     cout << cycle[i];
//                 }
//                 return;
//             }
//         }
//         cout<<"No negative cycle";
//     }
        
// };
// int main() {
//     int vertices, edges, source;
//     cin >> vertices;
//     cin >> edges;
//     cin >> source;

//     graph g(vertices, edges);

//     for (int i = 0; i < edges; ++i) {
//         int u, v, weight;
//         cin >> u >> v >> weight;
//         g.addedge(u, v, weight);
//     }

//     g.negativeO(source);

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, weight;
    Edge(int u, int v, int weight) {
        this->u = u;
        this->v = v;
        this->weight = weight; // Fixed: assign weight correctly
    }
};

class Graph {
public:
    int ver, edge;
    vector<Edge> edgelist;

    Graph(int ver, int edge) {
        this->ver = ver;
        this->edge = edge;
    }

    void addedge(int u, int v, int weight) {
        edgelist.push_back(Edge(u, v, weight));
    }

    void negativeO(int src) {
        vector<int> dist(ver + 1, numeric_limits<int>::max());
        vector<int> parent(ver + 1, -1);
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i <= ver - 1; ++i) {
            for (const Edge& edge : edgelist) {
                if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.weight; // Fixed: assignment
                    parent[edge.v] = edge.u;
                }
            }
        }

        // Check for negative-weight cycles
        int cycsrt = -1;
        for (const Edge& edge : edgelist) {
            if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.weight < dist[edge.v]) {
                cycsrt = edge.v;

                // Backtrack to find the start of the cycle
                for (int i = 0; i < ver; ++i) {
                    cycsrt = parent[cycsrt];
                }

                // Reconstruct the cycle
                vector<int> cycle;
                int current = cycsrt;
                do {
                    cycle.push_back(current);
                    current = parent[current];
                } while (current != cycsrt);
                cycle.push_back(cycsrt);
                reverse(cycle.begin(), cycle.end());

                // Print the cycle without repeating the start vertex
                cout << "Negative weight cycle: ";
                for (size_t i = 0; i < cycle.size() - 1; ++i) {
                    cout << cycle[i] << " "; // Fixed: added space for readability
                }
                cout << endl;
                return;
            }
        }

        cout << "No negative cycle" << endl;
    }
}; // Make sure to close the class 'Graph'

int main() {
    int vertices, edges, source;
    cin >> vertices >> edges >> source;

    Graph g(vertices, edges);

    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addedge(u, v, weight);
    }

    g.negativeO(source);

    return 0;
} // Close the main() function correctly
