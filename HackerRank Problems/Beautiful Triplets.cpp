// problem link: https://www.hackerrank.com/contests/world-codesprint-april/challenges/beautiful-triplets

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
    int n, d, ans=0;
    cin>>n>>d;
    unordered_map<int,int>freq_map;
    while(n--){
        int num;
        cin>>num;
        if(freq_map.count(num - d) != 0 && freq_map.count(num - 2*d) != 0)
            ans += (freq_map[num - d] * freq_map[num - 2*d]);
        freq_map[num]++;
    }
    cout<<ans<<'\n';

    return 0;
}
