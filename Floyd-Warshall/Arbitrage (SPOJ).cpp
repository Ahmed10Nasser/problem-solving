// Problem Link : https://vjudge.net/problem/SPOJ-ARBITRAG

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



void floyed(vector<vector<double>>& dis){
  int n=dis.size();
  for(int k=0; k<n; k++)
    for(int u=0; u<n; u++)
      for(int v=0; v<n; v++)
        if(dis[u][v] < dis[u][k] * dis[k][v])
          dis[u][v] = dis[u][k] * dis[k][v];
}



int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
 
  int n, tc=0;
  while(cin>>n, n){
    unordered_map<string,int>nameToIs;
    for(int i=0; i<n; i++){
      string s;
      cin>>s;
      nameToIs[s]=i;
    }
    int m;
    cin>>m;
    vector<vector<double>>dis(n, vector<double>(n, -LOO));
    for(int i=0; i<n; i++) dis[i][i]=1;
    for(int i=0; i<m; i++){
      string a,b;
      double c;
      cin>>a>>c>>b;
      int u=nameToIs[a], v=nameToIs[b];
      dis[u][v]=max(dis[u][v], c);
    }
    floyed(dis);
    bool ans=0;
    for(int i=0; i<n && ans==0; i++)
      if(dis[i][i] > 1)
        ans=1;
    if(ans)
      cout<<"Case "<<++tc<<": Yes\n";
    else
      cout<<"Case "<<++tc<<": No\n";

  }



  return 0;
}
