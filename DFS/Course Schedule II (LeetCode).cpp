// Problem Link : https://leetcode.com/problems/course-schedule-ii/

class Solution {
private:
  bool DFS(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& finishedPost, vector<int>& path){
    vis[node]=1;
    bool isCyclic=0;
    for(auto& neigh : adj[node]){
      if(vis[neigh]==0)
        isCyclic= isCyclic || DFS(neigh, adj, vis, finishedPost, path);
      else if(finishedPost[neigh]==0)
        isCyclic=1;
    }
    finishedPost[node]=1;
    path.push_back(node);
    return isCyclic;
  }
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>>adj(numCourses);
      vector<bool>vis(numCourses,0), finishedPost(numCourses, 0);
      vector<int> path;
      for(auto& edge : prerequisites){
        auto a=edge[0], b=edge[1];
        adj[a].push_back(b);
      }
      bool isCyclic=0;
      for(int i=0; i<numCourses && isCyclic==0; i++)
        if(vis[i]==0)
          isCyclic = isCyclic || DFS(i,adj,vis,finishedPost, path);
      
      if(isCyclic) return {};
      return path;
  }
};
