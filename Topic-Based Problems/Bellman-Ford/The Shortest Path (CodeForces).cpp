// https://vjudge.net/problem/Gym-101498L

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;




ll Bellman(int n, vector<pair<int,pair<int,int>>>& edges){
  vector<ll>dis(n, 0);
  bool hasNegCycle=0;
  for(int i=1; i<=n; i++){
    bool isUpdated=0;
    for(auto& edge : edges){
      auto cost=edge.first;
      auto fromNode=edge.second.first;
      auto toNode=edge.second.second;
      if(dis[toNode] > dis[fromNode] + cost){
        dis[toNode] = dis[fromNode] + cost;
        isUpdated=1;
      }
    }
    if(isUpdated==0) break;
    else if(i==n) hasNegCycle=1;
  }
  if(hasNegCycle) return -LOO;
  return *min_element(dis.begin(), dis.end());  

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
    vector<pair<int,pair<int,int>>>edges(m);
    int mn=INT_MAX;
    for(auto& edge : edges){
      cin>>edge.second.first>>edge.second.second>>edge.first;
      edge.second.first--, edge.second.second--;
      mn=min(mn, edge.first);
    }
    auto ans=Bellman(n,edges);
    if(ans==-LOO)
      cout<<"-inf\n";
    else if(ans<0)
      cout<<ans<<'\n';
    else
      cout<<mn<<'\n';



  }


  return 0;
}
