// Problem Link : https://vjudge.net/problem/UVA-10405

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


int solve(int i, int j, string& a, string& b, vector<vector<int>>& mem){
  if(i==a.length() || j==b.length()) return 0;
  if(mem[i][j]!=-1) return mem[i][j];
  if(a[i]==b[j]) return mem[i][j]= solve(i+1,j+1, a, b, mem) + 1;
  int op1=solve(i, j+1, a, b, mem);
  int op2=solve(i+1, j, a, b, mem);
  return mem[i][j]=max(op1, op2);
}



int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  string a,b;
  while(getline(cin, a) && getline(cin, b)){
    int n=a.length(), m=b.length();
    vector<vector<int>>mem(n, vector<int>(m, -1));
    cout<<solve(0,0,a,b,mem)<<'\n';
  }

  return 0; 
} 

