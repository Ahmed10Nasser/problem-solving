// Problem Link : https://vjudge.net/problem/UVA-869

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



void floyed(vector<vector<bool>>& trips){
  int n=trips.size();
  for(int k=0; k<n; k++)
    for(int u=0; u<n; u++)
      for(int v=0; v<n; v++)
        trips[u][v]= trips[u][v] || (trips[u][k]+trips[k][v]==2);
}

int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t, tc=0, n=26;
  cin>>t;
  while(t--){
    int m;
    cin>>m;
    vector<vector<bool>>trips1(n, vector<bool>(n, 0));
    for(int i=0; i<n; i++) trips1[i][i]=1;
    while(m--){
      char u,v;
      cin>>u>>v;
      trips1[u-'A'][v-'A']=1;
    }
    cin>>m;
    vector<vector<bool>>trips2(n, vector<bool>(n, 0));
    for(int i=0; i<n; i++) trips2[i][i]=1;
    while(m--){
      char u,v;
      cin>>u>>v;
      trips2[u-'A'][v-'A']=1;
    }
    floyed(trips1);
    floyed(trips2);
    bool ans=1;
    for(int i=0; i<n && ans; i++)
      for(int j=0; j<n && ans; j++)
        ans=(trips1[i][j] == trips2[i][j]);
    
    if(tc) cout<<'\n';
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
    ++tc;

  }


  return 0;
}
