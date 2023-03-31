// Problem Link : https://vjudge.net/problem/CodeForces-545C

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



int solve(int i, bool isLsRight, vector<int>& x, vector<int>& h, vector<vector<int>>& mem){
  if(i==x.size()) return 0;
  if(mem[i][isLsRight]!=-1) return mem[i][isLsRight];

  int op1=solve(i+1, 0, x, h, mem);
  int op2=(i==x.size()-1 || x[i]+h[i] < x[i+1]) ? solve(i+1, 1, x, h, mem) + 1 : INT_MIN;
  int op3=(i==0 || (isLsRight && x[i-1]+h[i-1] < x[i]-h[i]) || (!isLsRight && x[i-1] < x[i]-h[i])) ? solve(i+1,0,x,h,mem) + 1 : INT_MIN;

  return mem[i][isLsRight]=max({op1, op2, op3});
}




int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  cin>>n;
  vector<int>x(n), h(n);
  for(int i=0; i<n; i++) cin>>x[i]>>h[i];
  vector<vector<int>>mem(n, vector<int>(2, -1));
  cout<<solve(0,0,x,h,mem)<<'\n';  



  return 0;
} 


