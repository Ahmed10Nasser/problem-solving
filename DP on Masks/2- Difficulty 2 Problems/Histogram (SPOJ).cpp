// Problem Link :  https://vjudge.net/problem/SPOJ-HIST2

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


pair<int,ll> solve(int ls, int mask, vector<int>& h, vector<vector<pair<int,ll>>>& mem){
  int n=h.size()-1;
  if(mask == (1<<n)-1) return {h[ls],1};
  if(mem[ls][mask].first!=-1) return mem[ls][mask];
  pair<int,ll>ret={-OO, 0};
  for(int nxt=0; nxt<n; nxt++){
    if((mask>>nxt)&1) continue;
    auto op=solve(nxt,mask | (1<<nxt), h, mem);
    op.first+=abs(h[nxt]-h[ls]);
    if(op.first > ret.first) ret=op;
    else if(op.first == ret.first) ret.second+=op.second;
  }
  return mem[ls][mask]=ret;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  while(cin>>n, n){
    vector<int>h(n+1);
    vector<vector<pair<int,ll>>>mem(n+1, vector<pair<int,ll>>(1<<n, {-1,-1}));
    for(int i=0; i<n; i++) cin>>h[i];
    h[n]=0;
    auto ans=solve(n,0,h,mem);
    cout<<ans.first + 2*n<<' '<<ans.second<<'\n';

  }


  return 0;
} 

