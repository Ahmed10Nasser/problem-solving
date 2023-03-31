// Problem Link : https://vjudge.net/problem/CodeForces-414B

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

ll solve(int ls, int len, int k,int n, vector<vector<ll>>& mem){
  if(len==k) return 1;
  if(mem[ls][len]!=-1) return mem[ls][len];
  ll ret=0;
  for(int nxt=ls; nxt<=n; nxt+=ls)
    ret = (ret+solve(nxt,len+1, k, n, mem))%MOD;
  return mem[ls][len]=ret;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,k;
  cin>>n>>k;
  vector<vector<ll>>mem(n+1, vector<ll>(k, -1));
  cout<<solve(1, 0, k, n, mem)<<'\n';


  return 0;
} 


