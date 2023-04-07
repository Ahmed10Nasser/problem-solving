// Problem Link : https://vjudge.net/problem/CodeForces-166E

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;




int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int n;
  cin>>n;
  ll prevA=0, prevB=0, prevC=0, prevD=1;
  ll currA, currB, currC, currD;
  for(int i=1; i<=n; i++){
    currA = (prevB + prevC + prevD) % MOD;
    currB = (prevA + prevC + prevD) % MOD;
    currC = (prevA + prevB + prevD) % MOD;
    currD = (prevA + prevB + prevC) % MOD;
    prevA=currA;
    prevB=currB;
    prevC=currC;
    prevD=currD;
  }
  cout<<currD<<'\n';


  return 0;
} 



