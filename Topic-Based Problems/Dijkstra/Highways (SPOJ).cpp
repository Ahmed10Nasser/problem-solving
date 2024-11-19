// Problem Link : https://vjudge.net/problem/SPOJ-HIGHWAYS

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



int Dijkstra(int src, int tar, vector<vector<pair<int,int>>>& adj){
  vector<int> dis(adj.size(), INT_MAX);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  dis[src]=0;
  pq.push({dis[src],src});
  while(!pq.empty()){
    auto node=pq.top().second;
    auto candidateDis=pq.top().first;
    pq.pop();
    if(candidateDis != dis[node]) continue;
    // dis[node] is finalized
    if(node==tar) break;
    for(auto& pr : adj[node]){
      auto neigh=pr.first;
      auto cost = pr.second;
      if(dis[neigh] > dis[node] + cost){
        dis[neigh] = dis[node] + cost;
        pq.push({dis[neigh], neigh});
      }
    }
  }
  return dis[tar];
}



int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t;
  cin>>t;
  while(t--){
    int n,m,src,tar;
    cin>>n>>m>>src>>tar;
    src--,tar--;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0; i<m; i++){
      int u,v,c;
      cin>>u>>v>>c;
      u--,v--;
      adj[u].push_back({v,c});
      adj[v].push_back({u,c});
    }
    auto ans=Dijkstra(src, tar, adj);
    if(ans==INT_MAX) cout<<"NONE\n";
    else cout<<ans<<'\n';

  }


  return 0; 
} 

