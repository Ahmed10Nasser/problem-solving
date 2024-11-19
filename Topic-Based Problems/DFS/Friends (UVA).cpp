// Problem Link : https://vjudge.net/problem/UVA-10608

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


int DFS(int node, vector<vector<int>>& adj, vector<bool>& vis){
  vis[node]=1;
  int count=1;
  for(auto& neigh : adj[node])
    if(vis[neigh]==0)
      count+=DFS(neigh, adj, vis);
  return count;
}


int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t;
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
    vector<bool>vis(n,0);
    int maxGroup=1;
    for(int i=0; i<n; i++)
      if(vis[i]==0)
        maxGroup=max(maxGroup, DFS(i,adj,vis));
    
    cout<<maxGroup<<'\n';

  }


  return 0;
}
