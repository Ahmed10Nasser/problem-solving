// Problem Link : https://leetcode.com/problems/number-of-provinces/


class Solution {
private:
  void DFS(int node, vector<vector<int>>& isConnected, vector<bool>& vis){
    vis[node]=1;
    for(int neigh=0; neigh<isConnected.size(); neigh++)
      if(isConnected[node][neigh]==1 && vis[neigh]==0)
        DFS(neigh,isConnected,vis);
  }
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    vector<bool>vis(isConnected.size(),0);
    int componests=0;
    for(int i=0; i<isConnected.size(); i++){
      if(vis[i]==0){
        DFS(i,isConnected, vis);
        componests++;
      }
    }
    return componests;
  }
};
