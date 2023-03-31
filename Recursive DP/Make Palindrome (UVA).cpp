// Problem Link : https://vjudge.net/problem/UVA-10453

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

int solve(int l, int r, string&s , vector<vector<int>>& mem){
  if(l>r) return 0;
  if(mem[l][r]!=-1) return mem[l][r];
  if(s[l]==s[r]) return mem[l][r] = solve(l+1,r-1, s, mem);
  int op1=solve(l+1,r, s, mem) + 1;
  int op2=solve(l,r-1,s,mem) + 1;
  return mem[l][r]=min(op1,op2);
}


void getPath(int l, int r, string&s , vector<vector<int>>& mem, string& ans){
  if(l>r) return ;
  if(s[l]==s[r]){
    if(l==r) ans+=s[l];
    else{
      ans+=s[l];
      getPath(l+1, r-1, s, mem, ans);
      ans+=s[r];
    }
    return;
  }
  int opt=solve(l,r,s,mem);
  int op1=solve(l+1,r, s, mem) + 1;
  int op2=solve(l,r-1,s,mem) + 1;
  if(opt==op1){
    ans+=s[l];
    getPath(l+1,r,s,mem,ans);
    ans+=s[l];
    return;
  }
  ans+=s[r];
  getPath(l,r-1,s,mem,ans);
  ans+=s[r];
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  string s;
  while(cin>>s){
    int n=s.length();
    vector<vector<int>>mem(n, vector<int>(n, -1));
    cout<<solve(0,n-1, s, mem)<<' ';
    string ans="";
    getPath(0,n-1,s,mem,ans);
    cout<<ans<<'\n';
  }
  


  return 0;
} 


