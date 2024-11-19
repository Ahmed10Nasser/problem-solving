// Problem Link : https://vjudge.net/problem/CodeForces-455A

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;




ll solve(int i, vector<int>& freq, vector<ll>& mem){
  if(i>=freq.size()) return 0;
  if(mem[i]!=-1) return mem[i];
  ll op1=solve(i+2, freq, mem) + (ll)i*freq[i];
  ll op2=solve(i+1, freq, mem);
  return mem[i]=max(op1,op2);
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  cin>>n;
  vector<int>arr(n);
  for(auto& x : arr) cin>>x;
  int mx=*max_element(arr.begin(), arr.end());
  vector<int>freq(mx+1, 0);
  vector<ll>mem(mx+1, -1);
  for(auto& x : arr) freq[x]++;
  cout<<solve(*min_element(arr.begin(), arr.end()), freq, mem)<<'\n';



  return 0;
} 


