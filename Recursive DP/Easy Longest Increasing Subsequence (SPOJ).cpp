// Problem Link : https://vjudge.net/problem/SPOJ-ELIS

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

int solve(int i, int ls, vector<int>& arr, vector<vector<int>>& mem){
  if(i==arr.size()) return 0;
  if(mem[i][ls]!=-1) return mem[i][ls];
  int op1= (arr[i] > ls) ? solve(i+1, arr[i], arr, mem) + 1 : INT_MIN;
  int op2= solve(i+1, ls, arr, mem);
  return mem[i][ls] = max(op1, op2);
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  cin>>n;
  vector<int>arr(n);
  for(auto& x : arr) cin>>x;
  vector<vector<int>> mem(n, vector<int>(20+1, -1));
  cout<<solve(0, 0, arr, mem)<<'\n';

  return 0; 
} 

