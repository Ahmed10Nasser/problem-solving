// Problem Link : https://vjudge.net/problem/POJ-1260

#include <iostream>
#include <vector>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



int solve(int i, vector<int>& mem, vector<int>& cnt, vector<int>& price){
  if(i==cnt.size()) return 0;
  if(mem[i]!=-1) return mem[i];
  int sum=10;
  int ret=OO;
  for(int j=i; j<cnt.size(); j++){
    sum+=cnt[j];
    ret=min(ret, sum*price[j] + solve(j+1, mem, cnt, price));
  }
  return mem[i]=ret;
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>cnt(n), price(n), mem(n,-1);
    for(int i=0; i<n; i++) cin>>cnt[i]>>price[i];
    cout<<solve(0,mem,cnt,price)<<'\n';
  }


  return 0;
} 



