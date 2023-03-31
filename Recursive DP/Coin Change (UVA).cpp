// Problem Link : https://vjudge.net/problem/UVA-674

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


ll solve(int i, int rem, vector<int>& coins, vector<vector<ll>>& mem){
  if(rem==0) return 1;
  if(i==coins.size()) return 0;
  if(mem[i][rem]!=-1) return mem[i][rem];
  ll op1= (rem >= coins[i]) ? solve(i, rem-coins[i], coins, mem) : 0;
  ll op2= solve(i+1, rem, coins, mem);
  return mem[i][rem] = op1 + op2;
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  vector<int>coins={1,5,10,25,50};
  vector<vector<ll>>mem(coins.size(), vector<ll>(7489+1, -1));
  int n;
  while(cin>>n){
    cout<<solve(0,n,coins,mem)<<'\n';
  }

  return 0; 
} 

