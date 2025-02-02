#include<bits/stdc++.h>
using namespace std;

bool instack(int node, stack<int>& st){
  stack<int> temp = st;  
  while(!temp.empty()){
    if(temp.top() == node)
        return true;
    temp.pop();
  }
  return false;
}

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ll, vector<vector<int>>& sccs, stack<int>& st){
  visited[node] = 1;
  ll[node] = node;
  st.push(node);
  
  for(int i = 0; i < adj[node].size(); i++){
      int neighbor = adj[node][i];
      if(!visited[neighbor]){
        dfs(neighbor, adj, visited, ll, sccs, st);
        ll[node] = min(ll[node], ll[neighbor]);  
      }
      else if(instack(neighbor, st)){
        ll[node] = min(ll[node], ll[neighbor]);  
      }
  }   
  
  
  if(ll[node] == node){
    vector<int> scc;
    while(st.top() != node){
      scc.push_back(st.top());
      st.pop();
    }
    scc.push_back(st.top());
    st.pop();
    sccs.push_back(scc);  
  }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    
    for(int i = 0; i < n; i++){
        int nbr;
        cin >> nbr;
        for(int j = 0; j < nbr; j++){
          int u;
          cin >> u;
          adj[i].push_back(u);
        }
    }
    
    vector<int> visited(n, 0);
    vector<int> ll(n, 0);
    vector<vector<int>> sccs;
    stack<int> st;
    
    
    for(int i = 0; i < n; i++){
      if(!visited[i])
          dfs(i, adj, visited, ll, sccs, st);
    }
    
   
    for(auto& scc : sccs){
      for(auto& node : scc){
        cout << node << " ";
      }
      cout << "\n";
    }
}