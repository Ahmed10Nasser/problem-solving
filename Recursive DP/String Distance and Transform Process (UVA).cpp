// Problem Link : https://vjudge.net/problem/UVA-526

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


int solve(int i, int j, string& a, string& b, vector<vector<int>>& mem){
  if(i==a.length()) return b.length() - j;
  if(j==b.length()) return a.length() - i;
  if(mem[i][j]!=-1) return mem[i][j];
  if(a[i]==b[j]) return mem[i][j]=solve(i+1,j+1,a,b,mem);
  int op1=solve(i+1,j,a,b,mem) + 1;
  int op2=solve(i,j+1,a,b,mem) + 1;
  int op3=solve(i+1,j+1,a,b,mem) + 1;
  return mem[i][j]=min({op1,op2,op3});
}


void printPath(int i, int j, string& a, string& b, vector<vector<int>>& mem, int& shift, int& opNum){
  if(i==a.length()){
    for(int k=0; k<b.length()-j; k++)
      cout<<++opNum<<" Insert "<<i+k+shift + 1<<','<<b[j+k]<<'\n';
    shift+=(b.length()-j);
    return;
  }
  if(j==b.length()){
    for(int k=0; k<a.length()-i; k++){
      cout<<++opNum<<" Delete "<<i+k+shift + 1<<'\n';
      shift--;
    }
    return;
    
  }
  if(a[i]==b[j]){
    printPath(i+1,j+1,a,b,mem, shift, opNum);
    return;
  }
  int opt=solve(i,j,a,b,mem);
  int op1=solve(i+1,j,a,b,mem) + 1;
  int op2=solve(i,j+1,a,b,mem) + 1;
  int op3=solve(i+1,j+1,a,b,mem) + 1;
  if(opt==op1){
    cout<<++opNum<<" Delete "<<i+shift + 1<<'\n';
    shift--;
    printPath(i+1,j,a,b,mem,shift,opNum);
    return;
  }
  if(opt==op2){
    cout<<++opNum<<" Insert "<<i+shift + 1<<','<<b[j]<<'\n';
    shift++;
    printPath(i,j+1,a,b,mem,shift,opNum);
    return;
  }
  cout<<++opNum<<" Replace "<<i+shift + 1<<','<<b[j]<<'\n';
  printPath(i+1,j+1,a,b,mem,shift,opNum);
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  string a,b;
  int cnt=0;
  while(getline(cin,a)){
    getline(cin,b);
    vector<vector<int>>mem(a.length(), vector<int>(b.length(), -1));
    if(cnt) cout<<'\n';
    cout<<solve(0,0,a,b,mem)<<'\n';
    int shift=0, opNum=0;
    printPath(0,0,a,b,mem,shift,opNum);
    ++cnt;

  }


  return 0;
} 


