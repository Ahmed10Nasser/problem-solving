// problem link: https://codeforces.com/problemset/problem/1421/A

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
    
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int x = a&b;
        cout<< (a^x) + (b^x) <<'\n';
    }

    return 0;
}
