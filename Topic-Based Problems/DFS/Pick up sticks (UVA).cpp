// Problem Link : https://vjudge.net/problem/UVA-11686

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

bool DFS(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& finishPost, vector<int>& topological){
  vis[node]=1;
  bool isCyclic=0;
  for(int& neigh : adj[node])
    if(vis[neigh]==0)
      isCyclic = isCyclic || DFS(neigh, adj, vis,finishPost, topological);
    else if(finishPost[neigh]==0)
      isCyclic=1;
  finishPost[node]=1; 
  topological.push_back(node);
  return isCyclic;
}

int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);

  int n,m;
  while(cin>>n>>m, n || m){
    vector<vector<int>>adj(n);
    for(int i=0; i<m; i++){
      int u,v;
      cin>>u>>v;
      u--,v--;
      adj[v].push_back(u);
    }

    vector<bool>vis(n,0), finishPost(n, 0);
    vector<int>topological;

    bool isCyclic=0;

    for(int i=0; i<n; i++)
      if(vis[i]==0)
        isCyclic = isCyclic || DFS(i,adj,vis,finishPost, topological);
    
    if(isCyclic)
      cout<<"IMPOSSIBLE\n";
    else{
      for(auto& node : topological)
        cout<< node+1<<'\n';
    }
  }

  return 0;
}
