// Problem Link : https://vjudge.net/problem/UVA-10305

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


void DFS(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& path){
  vis[node]=1;
  for(int& neigh : adj[node])
    if(vis[neigh]==0)
      DFS(neigh, adj, vis, path);
  path.push_back(node);
}

 

int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,m;
  while(cin>>n>>m, n || m){
    vector<vector<int>>adj(n);
    vector<bool>vis(n,0);
    vector<int>path;
    for(int i=0; i<m; i++){
      int u,v;
      cin>>u>>v;
      u--,v--;
      adj[v].push_back(u);
    }
    for(int i=0; i<n; i++)
      if(vis[i]==0)
        DFS(i,adj,vis,path);
    

    for(auto& node : path) cout<<node+1<<' ';
    cout<<'\n';

  }

  return 0;
}
