// Problem Link : https://vjudge.net/problem/UVA-10685

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


int DFS(int u, vector<vector<int>>& adj, vector<bool>& vis){
  int count=1;
  vis[u]=1;
  for(int& v : adj[u])
    if(!vis[v])
      count+=DFS(v, adj, vis);
  return count;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,m;
  while(cin>>n>>m, n||m){
    vector<vector<int>>adj(n);
    unordered_map<string,int>nameToId;
    vector<bool>vis(n,0);
    for(int i=0; i<n; i++){
      string s;
      cin>>s;
      nameToId[s]=i;
    }
    for(int i=0; i<m; i++){
      string a,b;
      cin>>a>>b;
      int u=nameToId[a];
      int v=nameToId[b];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int mx=1;
    for(int i=0; i<n; i++)
      if(!vis[i])
        mx=max(mx,DFS(i,adj,vis));

    cout<<mx<<'\n';
  }


  return 0;
} 


