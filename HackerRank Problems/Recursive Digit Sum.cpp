// problem link: https://www.hackerrank.com/challenges/recursive-digit-sum/problem

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;


string super_digit(string s, int k){
    if(s.length() * k == 1) return s;
    ll sum = 0;
    for(auto& d : s) sum+= (d-'0');
    sum*=k;
    return super_digit(to_string(sum), 1);
}


int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);    
    string s;
    int k;
    cin>>s>>k;
    cout<< super_digit(s, k)<<'\n';
    return 0;
}
