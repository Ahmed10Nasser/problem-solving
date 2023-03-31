// Problem Link : https://vjudge.net/problem/UVA-558

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


bool Bellman(int src, vector<vector<int>>& edges, int nodes){
  vector<int>dis(nodes, OO);
  dis[src]=0;
  bool hasNegCycle=0;
  for(int i=1; i<=nodes; i++){
    bool isUpdated=0;
    for(auto& edge : edges){
      auto cost=edge[0];
      auto fromNode=edge[1];
      auto toNode=edge[2];
      if(dis[toNode] > dis[fromNode] + cost){
        dis[toNode] = dis[fromNode] + cost;
        isUpdated=1;
      }
    }
    if(isUpdated==0) break;
    else if(i==nodes) hasNegCycle=1;
  }
  return hasNegCycle;
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
    vector<vector<int>>edges(m);
    for(auto& edge : edges){
      int u, v,c;
      cin>>u>>v>>c;
      edge={c,u,v};
    }
    auto hasNegCycle=Bellman(0, edges, n);
    if(hasNegCycle) cout<<"possible\n";
    else cout<<"not possible\n";
  }

  return 0;
} 

