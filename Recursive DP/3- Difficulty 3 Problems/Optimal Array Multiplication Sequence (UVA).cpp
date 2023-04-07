// Problem Link : https://vjudge.net/problem/UVA-348

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;




int solve(int s, int e, vector<vector<int>>& mem, vector<int>& row, vector<int>& col){
  if(s==e) return 0;
  if(mem[s][e]!=-1) return mem[s][e];
  int ret=INT_MAX;
  for(int i=s; i<e; i++)
    ret=min(ret, solve(s,i,mem,row,col) + solve(i+1,e,mem,row,col) + row[s]*col[i]*col[e]);
  return mem[s][e]=ret;
}


void Print(int s, int e, vector<vector<int>>& mem, vector<int>& row, vector<int>& col, vector<int>& before, vector<int>& after){
  if(s==e) return ;
  int opt=solve(s,e, mem, row, col);
  int md=-1;
  for(int i=s; i<e && md==-1; i++){
    int op= solve(s,i,mem,row,col)+solve(i+1,e,mem,row,col)+row[s]*col[i]*col[e];
    if(op==opt) md=i;
  }
  if(s!=md){
    before[s]++;
    after[md]++;
  }
  if(md+1!=e){
    before[md+1]++;
    after[e]++;
  }
  Print(s,md, mem, row, col, before, after);
  Print(md+1,e, mem, row, col, before, after);
}

int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n,tc=0;
  while(cin>>n,n){
    vector<int>before(n,0), after(n,0),row(n),col(n);
    vector<vector<int>>mem(n,vector<int>(n,-1));
    for(int i=0; i<n; i++) cin>>row[i]>>col[i];
    Print(0,n-1,mem,row,col,before,after);
    cout<<"Case "<<++tc<<": (";
    for(int i=0; i<n; i++){
        cout<<string(before[i],'(')<<'A'<<i+1<<string(after[i],')');
        if(i!=n-1)cout<<" x ";
    }
    cout<<")\n";
  }


  return 0;
} 



