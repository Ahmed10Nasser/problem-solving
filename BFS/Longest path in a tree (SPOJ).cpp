// Problem Link : https://vjudge.net/problem/SPOJ-PT07Z

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


pair<int,int> BFS(int src, vector<vector<int>>& adj){
  queue<int>q;
  vector<int>dis(adj.size(), -1);
  q.push(src);
  dis[src]=0;
  int node=src;
  while(!q.empty()){
    node=q.front();
    q.pop();
    for(auto& neigh : adj[node]){
      if(dis[neigh]==-1){
        dis[neigh]=dis[node]+1;
        q.push(neigh);
      }
    }
  }
  return {node, dis[node]};
}


int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  cin>>n;
  vector<vector<int>>adj(n);
  for(int i=0; i<n-1; i++){
    int u,v;
    cin>>u>>v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto firstRound=BFS(0,adj);
  auto secondRound=BFS(firstRound.first, adj);
  cout<<secondRound.second<<'\n';


  return 0;
}
