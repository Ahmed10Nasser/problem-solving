// Problem Link: https://codeforces.com/problemset/problem/1492/B

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;


int main(){
    FIO
    // freopen("input.txt","rt",stdin);
    // freopen("output.txt","wt",stdout);
    int t;
    cin>>t;
    while(t--){
        int n, mx=0;
        cin>>n;
        vector<int>arr(n), stops;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(arr[i] > mx){
                stops.push_back(i);
                mx = arr[i];
            }
        }
        int to=n-1;
        for(int i=stops.size()-1; i>=0; i--){
            int from=stops[i];
            for(int j=from; j<=to; j++) cout<<arr[j]<<' ';
            to=from-1;
        }
        cout<<'\n';
    }

  return 0;
}
