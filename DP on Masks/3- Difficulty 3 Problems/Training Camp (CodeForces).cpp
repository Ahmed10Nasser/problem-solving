// Problem Link : https://vjudge.net/problem/Gym-100676G

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


int solve(int d, int mask, vector<vector<int>>& mem, vector<int>& w, vector<int>& preqs){
  int n=w.size();
  if(mask == (1<<n)-1) return 0;
  if(mem[d][mask]!=-1) return mem[d][mask];
  int ret=0;
  for(int nxt=0; nxt<n; nxt++){
    if((mask>>nxt)&1) continue;
    if( (mask & preqs[nxt]) == preqs[nxt])
      ret=max(ret, solve(d+1,mask | (1<<nxt), mem, w, preqs) + (d+1)*w[nxt]);
  }
  return mem[d][mask]=ret;
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    cin.ignore();
    unordered_map<string,int>nameToId;
    vector<int>w(n), preqs(n,0);
    for(int i=0; i<n; i++){
      string s;
      getline(cin,s);
      int index=s.find_last_of(' ');
      string name=s.substr(0,index);
      nameToId[name]=i;
      w[i]=stoi(s.substr(index+1));
    }
    for(int i=0; i<m; i++){
      string s;
      getline(cin,s);
      int index=s.find_first_of('-');
      int u = nameToId[s.substr(0,index-1)];
      int v = nameToId[s.substr(index+4)];
      preqs[v] = preqs[v] | (1<<u);
    }
    vector<vector<int>>mem(n, vector<int>(1<<n, -1));
    cout<<solve(0,0,mem,w,preqs)<<'\n';
  }


  return 0;
} 
