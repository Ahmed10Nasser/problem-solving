// problem link: https://codeforces.com/problemset/problem/1360/B

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
        int n;
        cin>>n;
        vector<int>arr(n);
        for(auto& num : arr) cin>>num;
        sort(arr.begin(), arr.end());
        int min_diff = 1000;
        for(int i=0; i<n-1; i++)
            min_diff = min(min_diff, arr[i+1] - arr[i]);
        cout<<min_diff<<'\n';
    }

    return 0;
}

