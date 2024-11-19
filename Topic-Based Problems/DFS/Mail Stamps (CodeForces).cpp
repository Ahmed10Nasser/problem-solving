// Problem Link : https://vjudge.net/problem/CodeForces-29C

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int N=1e5, MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& path){
  vis[node]=1;
  path.push_back(node);
  for(auto& neigh : adj[node])
    if(vis[neigh]==0)
      DFS(neigh, adj, vis, path);
}
 

int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);


    int id=0;
    unordered_map<int,int>nameToId, idToName;
    vector<vector<int>>adj(N);
    vector<int>degree(N,0);
    int n;
    cin>>n;
    while(n--){
      int x,y;
      cin>>x>>y;
      if(nameToId.find(x)==nameToId.end()) nameToId[x]=id, idToName[id++]=x;
      if(nameToId.find(y)==nameToId.end()) nameToId[y]=id, idToName[id++]=y;
      int u=nameToId[x], v=nameToId[y];
      adj[u].push_back(v);
      adj[v].push_back(u);
      degree[u]++,degree[v]++;
    }
    int src=-1;
    for(int i=0; i<id && src==-1; i++)
      if(degree[i]==1)
        src=i;
    vector<bool>vis(id, 0);
    vector<int>path;
    DFS(src,adj,vis,path);
    for(auto& node : path) cout<<idToName[node]<<' ';
    cout<<'\n';



  return 0;
}
