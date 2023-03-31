// Problem Link : https://leetcode.com/problems/jump-game-iii/

class Solution {
private:
  bool DFS(int node, vector<int>& arr, vector<bool>& vis){
    vis[node]=1;
    bool found0=(arr[node]==0) ? true : false;
    for(int i=0; i<2; i++){
      int neigh=node + ((i==0) ? arr[node] : -arr[node]);
      if(neigh>=0 && neigh<arr.size() && vis[neigh]==0)
        found0 = found0 || DFS(neigh, arr, vis);
    }
    return found0;
  }
public:
  bool canReach(vector<int>& arr, int start) {
      vector<bool>vis(arr.size(), 0);
      return DFS(start, arr, vis);
  }
};
