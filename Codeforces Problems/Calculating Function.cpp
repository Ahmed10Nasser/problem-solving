// problem link: https://codeforces.com/problemset/problem/486/A

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1073741824, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);

  ll n;
  cin>>n;
  if(n%2==0)
    cout<< n/2 <<'\n';
  else
    cout << n/2 - n <<'\n';

  return 0;
}

