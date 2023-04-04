// Problem Link : https://vjudge.net/problem/CodeForces-295B

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
  vector<int>nodesToRemove(n);
  for(auto& node : nodesToRemove) cin>>node;
  vector<bool>isAdded(n, 0);
  vector<ll>ans(n);

  for(int i=n-1; i>=0; i--){
    int k=nodesToRemove[i]-1;
    isAdded[k]=1;
    ll sum=0;
    for(int u=0; u<n; u++){
      for(int v=0; v<n; v++){
        dis[u][v]=min(dis[u][v], dis[u][k] + dis[k][v]);
        if(isAdded[u] && isAdded[v]) sum+=dis[u][v];
      }
    }
    ans[i]=sum;
  }
  for(auto& sum : ans) cout<<sum<<' ';
  cout<<'\n';

  return 0;
} 



