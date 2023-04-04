// Problem Link : https://vjudge.net/problem/UVA-10048

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



void floyed(vector<vector<int>>& dis){
  int n=dis.size();
  for(int k=0; k<n; k++)
    for(int u=0; u<n; u++)
      for(int v=0; v<n; v++)
        if(dis[u][v] > max(dis[u][k] , dis[k][v]))
          dis[u][v] = max(dis[u][k] , dis[k][v]);
}



int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);

  int n,m,q, tc=0;
  while(cin>>n>>m>>q, n || m || q){
    vector<vector<int>>dis(n, vector<int>(n, INT_MAX));
    for(int i=0; i<n; i++) dis[i][i]=0;
    for(int i=0; i<m; i++){
      int u,v,c;
      cin>>u>>v>>c;
      u--,v--;
      dis[u][v]=dis[v][u]=min(dis[u][v], c);
    }
    floyed(dis);
    if(tc) cout<<'\n';
    cout<<"Case #"<<++tc<<'\n';
    while(q--){
      int src, des;
      cin>>src>>des;
      src--,des--;
      if(dis[src][des]==INT_MAX)
        cout<<"no path\n";
      else
        cout<<dis[src][des]<<'\n';
    }
  }

 




  return 0;
}
