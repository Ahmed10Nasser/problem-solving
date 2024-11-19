// Problem Link : https://vjudge.net/problem/UVA-10004

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
  int n;
  while(cin>>n, n){
    int m;
    cin>>m;
    vector<vector<int>>adj(n);
    vector<bool>vis(n,0), color(n,0);
    for(int i=0; i<m; i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    bool isBi=DFS(0,adj,vis,color);
    if(isBi) cout<<"BICOLORABLE.\n";
    else cout<<"NOT BICOLORABLE.\n";
  }


  return 0;
} 


