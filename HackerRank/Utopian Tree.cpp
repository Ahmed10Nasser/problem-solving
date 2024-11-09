// problem link: https://www.hackerrank.com/challenges/utopian-tree/problem

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-9;

int tree_cycles(int n){
    int height = 1;
    for(int i=1; i<=n; i++){
        if(i%2==0) height++;
        else height *= 2;
    }
    return height;
}

int main(){ 
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<< tree_cycles(n) <<'\n';
    }

    return 0;
}
