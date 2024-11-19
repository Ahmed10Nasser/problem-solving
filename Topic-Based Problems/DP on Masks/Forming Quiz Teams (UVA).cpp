// Problem Link : https://vjudge.net/problem/UVA-10911

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


double dis(int ax, int ay, int bx, int by){
  return hypot(ax-bx, ay-by);
}

double solve(int mask, vector<int>& x, vector<int>& y, vector<double>& mem){
  int n=x.size();
  if(mask == (1<<n)-1) return 0;
  if(mem[mask]!=-1) return mem[mask];
  double ret=DBL_MAX;
  int cur;
  for(cur=0; cur<n && ((mask>>cur)&1); cur++);
  for(int nxt=cur+1; nxt<n; nxt++){
    if((mask>>nxt)&1) continue;
    ret = min(ret, solve(mask | (1<<cur) | (1<<nxt), x, y, mem) + dis(x[cur], y[cur], x[nxt], y[nxt]));
  }
  return mem[mask]=ret;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,tc=0;
  while(cin>>n, n){
    n*=2;
    vector<int>x(n), y(n);
    for(int i=0; i<n; i++){
      string s;
      cin>>s>>x[i]>>y[i];
    }
    vector<double>mem(1<<n, -1);
    cout<<"Case "<<++tc<<": "<<fixed<<setprecision(2)<<solve(0,x,y,mem)<<'\n';
  }


  return 0;
} 

