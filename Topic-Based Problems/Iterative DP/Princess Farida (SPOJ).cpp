// Problem Link : https://vjudge.net/problem/SPOJ-FARIDA

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
  int t,tc=0;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto& x : arr) cin>>x;
    if(n==0){
      cout<<"Case "<<++tc<<": 0\n";
      continue;
    }
    vector<ll>dp(n);
    dp[0]=arr[0];
    if(n>1)dp[1]=max(0LL + arr[1], dp[0]);
    for(int i=2; i<n; i++)
      dp[i] = max(dp[i-2] + arr[i] , dp[i-1]); 
    cout<<"Case "<<++tc<<": "<<dp[n-1]<<'\n';
  }

  return 0;
} 



