// Problem Link : https://vjudge.net/problem/CodeForces-1249E

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

int solve(int i, bool isLsElv, vector<int>& a, vector<int>& b, int c, vector<vector<int>>& mem, vector<int>& ans){
  if(i==0) return mem[i][isLsElv]=ans[i]=0;
  if(mem[i][isLsElv]!=-1) return mem[i][isLsElv];
  int op1=solve(i-1,1,a,b,c,mem, ans) + b[i] + (!(isLsElv)*c);
  int op2=solve(i-1,0,a,b,c,mem, ans) + a[i];
  return mem[i][isLsElv]=ans[i]=min(op1,op2);
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,c;
  cin>>n>>c;
  vector<int>a(n),b(n);
  for(int i=1; i<n; i++) cin>>a[i];
  for(int i=1; i<n; i++) cin>>b[i];
  vector<vector<int>>mem(n, vector<int>(2,-1));
  vector<int>ans(n);
  solve(n-1,0,a,b,c,mem,ans);
  for(auto& x : ans) cout<<x<<' ';
  cout<<'\n';



  return 0;
} 


