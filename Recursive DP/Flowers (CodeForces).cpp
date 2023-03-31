// Problem Link : https://vjudge.net/problem/CodeForces-474D

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

ll solve(int rem, vector<ll>& mem, int k){
  if(rem==0) return 1;
  if(mem[rem]!=-1) return mem[rem];
  ll op1=solve(rem-1, mem, k);
  ll op2= (rem >= k) ? solve(rem-k, mem, k) : 0;
  return mem[rem]=(op1+op2)%MOD;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t,k;
  cin>>t>>k;
  int mx=1e5;
  vector<ll>mem(mx+1, -1);
  solve(mx, mem, k);
  for(int i=1; i<=mx; i++) mem[i] += mem[i-1];
  while(t--){
    int l,r;
    cin>>l>>r;
    cout<<(mem[r] - mem[l-1])%MOD<<'\n';
  }
  


  return 0;
} 


