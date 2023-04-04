// Problem Link : https://vjudge.net/problem/CodeForces-25C

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


void floyd(vector<vector<int>>& dis){
  int n=dis.size();
  for(int k=0; k<n; k++)
    for(int u=0; u<n; u++)
      for(int v=0; v<n; v++)
        dis[u][v]=min(dis[u][v], dis[u][k]+dis[k][v]);
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  cin>>n;
  vector<vector<int>>dis(n, vector<int>(n));
  for(auto& v : dis)
    for(auto& x : v)
      cin>>x;
  int m;
  cin>>m;
  while(m--){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    dis[a][b]=dis[b][a]=min(dis[a][b], c);
    ll sum=0;
    for(int u=0; u<n; u++){
      for(int v=0; v<n; v++){
        dis[u][v]=min({dis[u][v], dis[u][a] + dis[a][b] + dis[b][v], dis[u][b] + dis[b][a] + dis[a][v]});
        if(u>v) sum+=dis[u][v];
      }
    }
    cout<<sum<<' ';
  }
  cout<<'\n';

  return 0;
} 



