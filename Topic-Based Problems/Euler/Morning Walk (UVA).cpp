// Problem Link : https://vjudge.net/problem/UVA-10596

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


void DFS(int node, vector<vector<pair<int,int>>>& adj, vector<int>& degree, vector<bool>& visEdges, vector<int>& path){
  while(degree[node] > 0){
    auto edgeId=adj[node][degree[node]-1].second;
    if(visEdges[edgeId]){
      degree[node]--;
      continue;
    }
    visEdges[edgeId]=1;
    auto neigh=adj[node][--degree[node]].first;
    DFS(neigh, adj, degree, visEdges, path);
  }
  path.push_back(node);
}


vector<int> Euler(vector<vector<pair<int,int>>>& adj, int edges, vector<int>& degree){
  for(int node=0; node<adj.size(); node++)
    if(degree[node] & 1)
      return {};

  vector<int> path;
  vector<bool> visEdges(edges, 0);

  for(int node=0; node<adj.size(); node++){
    if(degree[node] > 0){
      DFS(node, adj, degree, visEdges, path);
      break;
    }
  }

  if(path.size()!=edges+1) return {};
  reverse(path.begin(), path.end());
  return path;
}



int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,m;
  while(cin>>n>>m){
    vector<vector<pair<int,int>>>adj(n);
    vector<int> degree(n, 0);
    for(int i=0; i<m; i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back({v,i});
      adj[v].push_back({u,i});
      degree[u]++;
      degree[v]++;
    }
    auto path=Euler(adj, m, degree);
    if(path.empty()) cout<<"Not Possible\n";
    else cout<<"Possible\n";
    
  }


  return 0; 
} 

