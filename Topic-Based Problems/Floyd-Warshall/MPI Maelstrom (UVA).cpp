// Problem Link : https://vjudge.net/problem/UVA-423

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



void floyed(vector<vector<ll>>& dis){
  int n=dis.size();
  for(int k=0; k<n; k++)
    for(int u=0; u<n; u++)
      for(int v=0; v<n; v++)
        if(dis[u][v] > dis[u][k] + dis[k][v])
          dis[u][v] = dis[u][k] + dis[k][v];
}



int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);

  int n;
  cin>>n;
  vector<vector<ll>> dis(n, vector<ll>(n , LOO));
  for(int i=0; i<n; i++){
    dis[i][i]=0;
    for(int j=0; j<i; j++){
      string s;
      cin>>s;
      if(s!="x") dis[i][j]=dis[j][i]=stoi(s);
    }
  }
  floyed(dis);
  cout<< *max_element(dis[0].begin(), dis[0].end()) << '\n';

 




  return 0;
}
