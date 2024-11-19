// Problem Link : https://vjudge.net/problem/SPOJ-MST

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


int findParent(int u, vector<int>& par){
  if(u==par[u]) return u;
  return par[u]=findParent(par[u], par);
}

void join(int a, int b, vector<int>& par, vector<int>& sz){
  a=findParent(a,par);
  b=findParent(b,par);
  if(a!=b){
    if(sz[b] > sz[a]) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
  }
}


ll kruskal(int n, vector<vector<int>>& edges){
  ll ret=0;
  vector<int>par(n), sz(n, 1);
  iota(par.begin(), par.end(), 0);
  sort(edges.begin(), edges.end());
  for(auto& edge : edges){
    if(findParent(edge[1],par)!=findParent(edge[2],par)){
      ret+=edge[0];
      join(edge[1], edge[2],par,sz);
    }
  }
  return ret;
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,m;
  cin>>n>>m;
  vector<vector<int>>edges;
  while(m--){
    int u,v,c;
    cin>>u>>v>>c;
    edges.push_back({c,--u,--v});
  }
  cout<<kruskal(n,edges)<<'\n';


  return 0;
} 


