// Problem Link : https://vjudge.net/problem/SPOJ-TRSTAGE

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



double solve(int u, int mask, vector<int>& horses, vector<vector<pair<int,int>>>& adj, vector<vector<double>>& mem, int dest){
  if(u==dest) return 0;
  if(mask==(1<<(int)(horses.size()))-1) return LOO;
  if(mem[u][mask]!=-1) return mem[u][mask];
  double ret=LOO;
  for(auto& edge : adj[u]){
    int v=edge.first;
    double dis=edge.second;
    for(int nxt=0; nxt<horses.size(); nxt++){
      if((mask>>nxt)&1) continue;
      ret=min(ret, solve(v, mask | (1<<nxt), horses, adj, mem, dest) + dis/horses[nxt]);
    }
  }
  return mem[u][mask]=ret;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t,n,m,src,dest;
  while(cin>>t>>n>>m>>src>>dest, t||n||m||src||dest){
    src--,dest--;
    vector<vector<pair<int,int>>>adj(n);
    vector<int>horses(t);
    vector<vector<double>>mem(n, vector<double>(1<<t, -1));
    for(auto& horse : horses) cin>>horse;
    for(int i=0; i<m; i++){
      int u,v,c;
      cin>>u>>v>>c;
      u--,v--;
      adj[u].push_back({v,c});
      adj[v].push_back({u,c});
    }
    auto ans=solve(src,0,horses, adj,mem, dest);
    if(ans==LOO) cout<<"Impossible\n";
    else cout<<fixed<<setprecision(3)<<ans<<'\n';
  }


  return 0;
} 

