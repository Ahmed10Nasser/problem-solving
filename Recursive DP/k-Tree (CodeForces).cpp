// Problem Link : https://vjudge.net/problem/CodeForces-431C

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
 
const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



ll solve(int rem, bool isGoED, vector<vector<ll>>& mem, int k, int d){
  if(rem==0) return isGoED;
  if(mem[rem][isGoED]!=-1) return mem[rem][isGoED];

  ll ret=0;
  for(int i=1; i<=k && i<=rem; i++)
    ret= (ret + solve(rem-i, isGoED || i>=d, mem, k, d)) % MOD;

  return mem[rem][isGoED]=ret;  
}

int main(){
  FIO
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,k,d;
  cin>>n>>k>>d;
  vector<vector<ll>>mem(n+1, vector<ll>(2,-1));
  cout<<solve(n, 0, mem, k, d)<<'\n';


  return 0;
}
