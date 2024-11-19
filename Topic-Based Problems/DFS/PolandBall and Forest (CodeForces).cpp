// Problem Link : https://vjudge.net/problem/CodeForces-755C

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


void DFS(int u, vector<vector<int>>& adj, vector<bool>& vis){
  vis[u]=1;
  for(int& v : adj[u])
    if(!vis[v])
      DFS(v, adj, vis);
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  cin>>n;
  vector<vector<int>>adj(n);
  vector<bool>vis(n,0);
  for(int u=0; u<n; u++){
    int v;
    cin>>v;
    adj[u].push_back(--v);
    adj[v].push_back(u);
  }
  int cnt=0;
  for(int i=0; i<n; i++){
    if(!vis[i]){
      cnt++;
      DFS(i,adj,vis);
    }
  }
  cout<<cnt<<'\n';


  return 0;
} 


