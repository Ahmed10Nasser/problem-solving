// Problem Link : https://vjudge.net/problem/AtCoder-abc061_d

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


ll Bellman(int src, int tar, vector<vector<int>>& edges, int nodes){
  vector<ll>dis(nodes, LOO);
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
  if(hasNegCycle==0) return dis[tar];
  vector<bool> affectedByNegCycle(nodes, 0);
  for(int i=1; i<=nodes-1; i++){
    for(auto& edge : edges){
      auto cost=edge[0];
      auto fromNode=edge[1];
      auto toNode=edge[2];
      if(dis[toNode] > dis[fromNode] + cost){
        dis[toNode] = dis[fromNode] + cost;
        affectedByNegCycle[toNode]=affectedByNegCycle[fromNode] = true;
      }
    }
  }
  if(affectedByNegCycle[tar]) return -LOO;
  return dis[tar];
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,m;
  cin>>n>>m;
  vector<vector<int>>edges(m);
  for(auto& edge : edges){
    int u,v,c;
    cin>>u>>v>>c;
    edge={-c,u-1,v-1};
  }
  auto ans=Bellman(0, n-1, edges, n);
  if(ans==-LOO) cout<<"inf\n";
  else cout<< -ans <<'\n';

  return 0;
} 

