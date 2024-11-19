// Problem Link : https://vjudge.net/problem/SPOJ-BUGLIFE

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


bool DFS(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& color){
  vis[node]=1;
  bool isBi=1;
  for(auto& neigh : adj[node]){
    if(vis[neigh]==0){
      color[neigh] = !color[node];
      isBi = isBi && DFS(neigh, adj, vis, color);
    }
    else if(color[neigh] == color[node])
      isBi=0;
  }
  return isBi;
}


int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);

  int t,tc=0;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0; i<m; i++){
      int u,v;
      cin>>u>>v;
      u--,v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    bool isBi=1;
    vector<bool>vis(n,0), color(n,0);
    for(int i=0; i<n && isBi==1; i++)
      if(vis[i]==0)
        isBi = isBi && DFS(i,adj,vis,color);
    
    cout<<"Scenario #"<<++tc<<":\n";
    if(isBi)
      cout<<"No suspicious bugs found!\n";
    else
      cout<<"Suspicious bugs found!\n";

  }

  return 0;
}
