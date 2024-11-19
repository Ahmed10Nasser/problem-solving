// Problem Link : https://vjudge.net/problem/CodeForces-34D

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


void DFS(int u, int par, vector<vector<int>>& adj, vector<int>& ans){
  ans[u]=par;
  for(int v : adj[u])
    if(v!=par)
      DFS(v, u, adj, ans);
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,r1,r2;
  cin>>n>>r1>>r2;
  r1--;
  r2--;
  vector<vector<int>>adj(n);
  vector<int>ans(n);
  for(int i=0; i<n; i++){
    if(i==r1) continue;
    int v;
    cin>>v;
    v--;
    adj[v].push_back(i);
    adj[i].push_back(v);
  }

  DFS(r2,-1,adj,ans);
  for(int i=0; i<n; i++){
    if(i==r2) continue;
    cout<<ans[i]+1<<' ';
  }
  cout<<'\n';


  return 0;
} 


