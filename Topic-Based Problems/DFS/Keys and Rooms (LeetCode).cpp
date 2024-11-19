// Problem Link : https://leetcode.com/problems/keys-and-rooms/

class Solution {
private:
  void DFS(int node, vector<vector<int>>& adj, vector<bool>& vis){
    vis[node]=1;
    for(auto& neigh : adj[node])
      if(vis[neigh]==0)
        DFS(neigh, adj, vis);
  }
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool>vis(rooms.size(),0);
    DFS(0,rooms, vis);
    return count(vis.begin(), vis.end(), 0)==0;
  }
};
