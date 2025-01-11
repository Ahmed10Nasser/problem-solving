// problem link: https://codeforces.com/problemset/problem/296/C

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;



int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);    
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> arr(n);
    for(auto& num : arr) cin>>num;
    vector<vector<int>> operations(m, vector<int>(3));
    for(auto& operation : operations)
        cin>>operation[0]>>operation[1]>>operation[2];
    
    vector<int>freq_of_operations(m, 0);
    while(k--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        freq_of_operations[l]++;
        if(r+1 < m) freq_of_operations[r+1]--;
    }
    for(int i=1; i<m; i++)
        freq_of_operations[i] += freq_of_operations[i-1];
    
    vector<ll>added(n, 0);
    for(int i=0; i<m; i++){
        int l=operations[i][0]-1, r=operations[i][1]-1;
        ll d=operations[i][2];
        ll added_val = d * freq_of_operations[i];
        added[l] += added_val;
        if(r+1 < n) added[r+1] -= added_val;
    }
    for(int i=1; i<n; i++)
        added[i] += added[i-1];
    for(int i=0; i<n; i++)
        cout<<arr[i] + added[i] <<' ';
    cout<<'\n';    



    return 0;
}
