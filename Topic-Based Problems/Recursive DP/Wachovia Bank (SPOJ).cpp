// Problem Link : https://vjudge.net/problem/SPOJ-WACHOVIA

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

int solve(int i, int rw, vector<vector<int>>& mem, vector<int>& coins, vector<int>& w){
  if(i==w.size()) return 0;
  if(mem[i][rw]!=-1) return mem[i][rw];
  int op1= (rw >= w[i]) ? solve(i+1, rw-w[i], mem, coins, w) + coins[i] : INT_MIN;
  int op2=solve(i+1, rw, mem, coins, w);
  return mem[i][rw] = max(op1,op2);
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t;
  cin>>t;
  while(t--){
    int W,n;
    cin>>W>>n;
    vector<int>coins(n), w(n);
    for(int i=0; i<n; i++) cin>>w[i]>>coins[i];
    vector<vector<int>>mem(n, vector<int>(W+1, -1));
    cout<<"Hey stupid robber, you can get "<<solve(0,W,mem,coins, w)<<".\n";

  }


  return 0; 
} 

