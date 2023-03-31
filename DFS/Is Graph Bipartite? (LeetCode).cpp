// Problem Link : https://leetcode.com/problems/is-graph-bipartite/

class Solution {
private:
  bool DFS(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& color){
    vis[node]=1;
    bool isBi=1;
    for(auto& neigh : adj[node]){
      if(vis[neigh]==0){
        color[neigh] = !color[node];
        isBi = isBi && DFS(neigh, adj, vis, color);
      }
      else if(color[node]==color[neigh])
        isBi=0;
    }
    return isBi;
  }

public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<bool>vis(n,0), color(n, 0);
    bool isBi=1;
    for(int node=0; node<n && isBi==1; node++)
      if(vis[node]==0)
        isBi = isBi && DFS(node, graph, vis, color);
    return isBi;
  }
};
