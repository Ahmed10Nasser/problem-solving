// Problem Link : https://vjudge.net/problem/UVA-10003

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



int solve(int sc, int ec, int sx, int ex, vector<vector<int>>& mem, vector<int>& xCuts){
  if(sc > ec) return 0;
  if(mem[sc][ec]!=-1) return mem[sc][ec];
  int ret=INT_MAX;
  for(int i=sc; i<=ec; i++)
    ret=min(ret, solve(sc,i-1, sx, xCuts[i], mem, xCuts)  +  solve(i+1,ec, xCuts[i]+1, ex, mem,xCuts) + (ex-sx+1));
  return mem[sc][ec]=ret;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int l;
  while(cin>>l, l){
    int n;
    cin>>n;
    vector<int>xCuts(n);
    for(auto& xCut : xCuts) cin>>xCut;
    vector<vector<int>>mem(n, vector<int>(n, -1));
    cout<<"The minimum cutting is "<<solve(0,n-1,1,l,mem,xCuts)<<".\n";
  }


  return 0;
} 



