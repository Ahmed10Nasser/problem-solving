// problem link: https://www.hackerrank.com/contests/being-zero/challenges/sum-vs-xor

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
    ll n;
    cin>>n;
    int num_of_zeros = 0;
    for(int i=0; (1LL<<i) <= n; i++)
        if(((n>>i)&1) == 0)
            num_of_zeros++;
    cout<< (1LL<<num_of_zeros) << '\n';

    return 0;
}
