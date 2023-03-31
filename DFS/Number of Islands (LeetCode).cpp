// Problem Link : https://leetcode.com/problems/number-of-islands/description/

class Solution {
private:
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    void DFS(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()) return;
        if(grid[r][c]=='0' || visited[r][c]) return;
        visited[r][c]=1;
        for(int i=0; i<4; i++) DFS(r+dr[i],c+dc[i],grid,visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,0));
        int numOfIslands=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    numOfIslands++;
                    DFS(i,j,grid,visited);
                }
            }
        }
        return numOfIslands;
    }
};
