// Problem Link : https://leetcode.com/problems/max-area-of-island/

class Solution {
  int dr[4]={0,0,1,-1};
  int dc[4]={1,-1,0,0};
  bool inBorder(int r, int c, int n, int m){
    return r>=0 && r<n && c>=0 && c<m;
  }
  int DFS(int nodeR, int nodeC, vector<vector<int>>& grid, vector<vector<bool>>& vis){
    vis[nodeR][nodeC]=1;
    int numOfNodes=1;
    for(int i=0; i<4; i++){
      int neighR=nodeR + dr[i];
      int neighC=nodeC + dc[i];
      if(inBorder(neighR, neighC, grid.size(), grid[0].size()) && grid[neighR][neighC]==1 && vis[neighR][neighC]==0)
        numOfNodes += DFS(neighR, neighC, grid, vis);
    }
    return numOfNodes;
  }

public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
      int n=grid.size(), m=grid[0].size();
      vector<vector<bool>>vis(n, vector<bool>(m, 0));
      int maxArea=0;
      for(int r=0; r<n; r++)
        for(int c=0; c<m; c++)
          if(grid[r][c]==1 && vis[r][c]==0)
            maxArea=max(maxArea, DFS(r,c,grid,vis));
      return maxArea;
  }
};
