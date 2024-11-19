// Problem Link : https://vjudge.net/problem/CodeForces-33B

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
  string a,b;
  int m,n=26;
  cin>>a>>b>>m;
  if(a.length()!=b.length()){
    cout<<"-1\n";
    return 0;
  }
  vector<vector<int>>dis(n, vector<int>(n, OO));
  for(int i=0; i<n; i++) dis[i][i]=0;
  for(int i=0; i<m; i++){
    char u,v;
    int c;
    cin>>u>>v>>c;
    dis[u-'a'][v-'a']=min(dis[u-'a'][v-'a'], c);
  }
  floyd(dis);

  string ans="";
  int totalCost=0;
  for(int i=0; i<a.length(); i++){
    int mnCost=OO;
    char toChar;
    for(char ch='a'; ch<='z'; ch++){
      if(dis[a[i]-'a'][ch-'a'] + dis[b[i]-'a'][ch-'a'] < mnCost){
        mnCost = dis[a[i]-'a'][ch-'a'] + dis[b[i]-'a'][ch-'a'];
        toChar=ch;
      }
    }
    if(mnCost==OO){
      cout<<"-1\n";
      return 0;
    }
    ans+=toChar;
    totalCost+=mnCost;
  }
  cout<<totalCost<<'\n'<<ans<<'\n';

  return 0;
} 



