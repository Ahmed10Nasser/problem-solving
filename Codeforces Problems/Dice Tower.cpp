// problem link: https://codeforces.com/problemset/problem/225/A

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
    int n,top;
    cin>>n>>top;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a==top || a==7-top || b==top || b==7-top){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";

    return 0;
}
