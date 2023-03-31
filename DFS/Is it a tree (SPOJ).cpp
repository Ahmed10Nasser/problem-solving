// Problem Link : https://vjudge.net/problem/SPOJ-PT07Y

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


void DFS(int node, vector<vector<int>>& adj, vector<bool>& vis){
  vis[node]=1;
  // pre-order execution
  for(auto& neigh : adj[node])
    if(vis[neigh]==0)
      DFS(neigh, adj, vis);
  // post-order execution
}


int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
 
  int n,m;
  cin>>n>>m;
  if(n!=m+1){
    cout<<"NO\n";
    return 0;
  }
  vector<vector<int>>adj(n);
  for(int i=0; i<m; i++){
    int u,v;
    cin>>u>>v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool>vis(n,0);
  DFS(0,adj,vis);
  int countOfZeros=count(vis.begin(), vis.end(), 0);
  if(countOfZeros>0) cout<<"NO\n";
  else cout<<"YES\n";


  return 0;
}
