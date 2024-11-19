// Probelm Link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
private:
  const int OO=0x3f3f3f3f;
  void Floyed(vector<vector<int>>& dis){
  int n=dis.size();
  for(int k=0; k<n; k++)
    for(int u=0; u<n; u++)
      for(int v=0; v<n; v++)
        if(dis[u][v] > dis[u][k] + dis[k][v])
          dis[u][v] = dis[u][k] + dis[k][v];
}
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n, vector<int>(n, OO));
        for(int i=0; i<n; i++) dis[i][i]=0;
        for(auto& edge : edges){
          auto fromNode=edge[0];
          auto toNode=edge[1];
          auto cost=edge[2];
          dis[fromNode][toNode]=dis[toNode][fromNode]=min(dis[fromNode][toNode], cost);
        }
        Floyed(dis);
        int ansNode=-1, minCities=n;
        for(int u=0; u<n; u++){
          int cities=0;
          for(int v=0; v<n; v++)
            if(u!=v && dis[u][v] <= distanceThreshold) cities++;
          if(cities <= minCities){
            minCities=cities;
            ansNode=u;
          }
        }
        return ansNode;
    }
};
