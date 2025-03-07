// problem link: https://www.hackerrank.com/challenges/the-great-xor/problem

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;



int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);    
    int t;
    cin>>t;
    while(t--){
        ll x, ans=0;
        cin>>x;
        for(int i=0; (1LL<<i) <= x; i++)
            if(((x>>i)&1) == 0)
                ans += (1LL<<i);
        cout<< ans << '\n';
    }

    return 0;
}
