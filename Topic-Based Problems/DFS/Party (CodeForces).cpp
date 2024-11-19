// Problem Link : https://vjudge.net/problem/CodeForces-115A

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


int DFS(int u, int level, vector<vector<int>>& adj){
  int mx=level;
  for(int& v : adj[u])
    mx=max(mx,DFS(v, level+1,adj));
  return mx;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  cin>>n;
  vector<vector<int>>adj(n);
  for(int i=0; i<n; i++){
    int manger;
    cin>>manger;
    if(manger==-1) continue;
    manger--;
    adj[manger].push_back(i);
  }
  int mx=1;
  for(int i=0; i<n; i++)
      mx=max(mx, DFS(i,1,adj));
  cout<<mx<<'\n';


  return 0;
} 


