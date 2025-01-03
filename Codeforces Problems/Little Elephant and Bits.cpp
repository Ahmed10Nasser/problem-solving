// problem link: https://codeforces.com/problemset/problem/258/A

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

    string s;
    cin>>s;
    bool found_zero = false;
    for(int i=0; i<s.length()-1; i++){
        if(!found_zero && s[i]=='0')
            found_zero = true;
        else
            cout<<s[i];
    }
    if(found_zero) cout<<s.back();
    cout<<'\n';


  return 0;
}

