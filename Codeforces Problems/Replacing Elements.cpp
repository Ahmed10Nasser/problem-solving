// problem link: https://codeforces.com/problemset/problem/1473/A

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
        int n,d;
        cin>>n>>d;
        vector<int>arr(n);
        bool found_greater_d = false;
        for(auto& num : arr){
            cin>>num;
            if(num > d) found_greater_d = true;
        }
        if(!found_greater_d){
            cout<<"YES\n";
            continue;
        }
        int min1=101, min2=101;
        for(auto num : arr){
            if(num < min1){
                min2 = min1;
                min1 = num;
            }
            else if(num < min2)
                min2 = num;
        }
        if(min1 + min2 <= d)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
