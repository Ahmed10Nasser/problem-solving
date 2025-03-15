// problem link: https://atcoder.jp/contests/abc191/tasks/abc191_b

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;


void remove_it(vector<int>& arr, int x, int i){
    if(i==arr.size()) return;
    if(arr[i] != x) cout<< arr[i]<<' ';
    remove_it(arr, x, i+1);
}


int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);    
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(auto& num : arr) cin>>num;
    remove_it(arr, x, 0);
    cout<<'\n';
    return 0;
}
