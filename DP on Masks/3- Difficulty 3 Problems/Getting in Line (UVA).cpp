// Problem Link : https://vjudge.net/problem/UVA-216

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



double dis(int ax, int ay, int bx, int by){
  return hypot(ax-bx,ay-by)+16;
}


double solve(int cur, int mask, vector<vector<double>>& mem, vector<int>& x, vector<int>& y){
  int n=x.size();
  if(mask==(1<<n)-1) return 0;
  if(mem[cur][mask]!=-1) return mem[cur][mask];
  double ret=LOO;
  for(int nxt=0; nxt<n; nxt++){
    if((mask>>nxt)&1) continue;
    ret=min(ret,dis(x[cur], y[cur], x[nxt], y[nxt])+solve(nxt, mask|(1<<nxt), mem, x, y));
  }
  return mem[cur][mask]=ret;
}

void Print(int cur, int mask, vector<vector<double>>& mem, vector<int>& x, vector<int>& y){
  int n=x.size();
  if(mask==(1<<n)-1) return;
  double opt=solve(cur,mask, mem, x, y);
  int Nxt=-1;
  for(int nxt=0; nxt<n && Nxt==-1; nxt++){
    if((mask>>nxt)&1) continue;
    double op=dis(x[cur], y[cur], x[nxt], y[nxt])+solve(nxt, mask|(1<<nxt), mem, x, y);
    if(op==opt)
      Nxt=nxt;
  }
  cout<<"Cable requirement to connect ("<<x[cur]<<','<<y[cur]<<") to ("<<x[Nxt]<<','<<y[Nxt]<<") is "<<dis(x[cur], y[cur], x[Nxt], y[Nxt])<<" feet.\n";
  Print(Nxt, mask|(1<<Nxt), mem, x, y);
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,tc=0;
  while(cin>>n,n){
    vector<int>x(n),y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];
    double mn=DBL_MAX;
    int st=-1;
    for(int i=0; i<n; i++){
      vector<vector<double>>mem(n, vector<double>(1<<n,-1));
      double ans=solve(i,1<<i, mem, x, y);
      if(ans<mn){
        mn=ans;
        st=i;
      }
    }
    vector<vector<double>>mem(n, vector<double>(1<<n,-1));
    solve(st,1<<st, mem, x, y);
    cout<<fixed<<setprecision(2);
    cout<<"**********************************************************\n";
    cout<<"Network #"<<++tc<<'\n';
    Print(st,1<<st, mem, x, y);
    cout<<"Number of feet of cable required is "<<mn<<".\n";
  }


  return 0;
} 
