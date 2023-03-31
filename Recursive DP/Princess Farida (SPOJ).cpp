// Problem Link : https://vjudge.net/problem/SPOJ-FARIDA

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


ll solve(int i, vector<int>& coins, vector<ll>& mem){
  if(i>=coins.size()) return 0;
  if(mem[i]!=-1) return mem[i];
  ll op1=solve(i+2, coins, mem) + coins[i];
  ll op2=solve(i+1,coins, mem);
  return mem[i]=max(op1,op2);
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t,tc=0;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>coins(n);
    for(auto& coin : coins) cin>>coin;
    vector<ll>mem(n,-1);
    cout<<"Case "<<++tc<<": "<<solve(0,coins, mem)<<'\n';
  }


  return 0;
} 


