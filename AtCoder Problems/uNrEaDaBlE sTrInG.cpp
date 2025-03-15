// problem link: https://atcoder.jp/contests/abc192/tasks/abc192_b

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;

bool is_hard_to_read(string& s, int i){
    if(i == s.length()) return true;
    if(i&1 && islower(s[i])) return false;
    if(!(i&1) && isupper(s[i])) return false;
    return is_hard_to_read(s, i+1);
}


int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);    
    string s;
    cin>>s;
    if(is_hard_to_read(s, 0)) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
