// problem link: https://atcoder.jp/contests/abc220/tasks/abc220_c

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
    int n;
    cin>>n;
    vector<int>arr(n);
    ll x,sum=0;
    for(auto& num : arr){
        cin>>num;
        sum += num;
    }
    cin>>x;
    ll num_of_full_arr = x / sum;
    sum *= num_of_full_arr;
    ll index = num_of_full_arr * n;
    for(auto num : arr){
        sum += num;
        index++;
        if(sum > x) break;
    }
    cout<< index << '\n';
    return 0;
}
