// Problem Link : https://vjudge.net/problem/CodeForces-430C

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


void DFS(int node, int par, int level, int even, int odd, vector<vector<int>>& adj, vector<int>& initial, vector<int>& goal, vector<int>& ans){
  if(level&1) initial[node] = (odd&1) ? !initial[node] : initial[node];
  else initial[node] = (even&1) ? !initial[node] : initial[node];
  if(initial[node]!=goal[node]){
    initial[node]=goal[node];
    ans.push_back(node);
    if(level&1) odd++;
    else even++;
  }

  for(int& neigh : adj[node])
    if(neigh!=par)
      DFS(neigh,node,level+1,even,odd,adj,initial,goal,ans);
}

int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  cin>>n;
  vector<vector<int>>adj(n);
  vector<int>initial(n),goal(n),ans;
  for(int i=0; i<n-1; i++){
    int u,v;
    cin>>u>>v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(auto& x : initial) cin>>x;
  for(auto& x : goal) cin>>x;
  DFS(0,-1,0,0,0,adj,initial,goal,ans);
  cout<<(int)ans.size()<<'\n';
  for(auto& x : ans) cout<<x+1<<'\n';

  return 0;
}
