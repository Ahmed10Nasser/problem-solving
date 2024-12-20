// problem link: https://codeforces.com/problemset/problem/1526/C2

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
    priority_queue<int, vector<int>, greater<int>> min_heap;
    ll health = 0;
    while(n--){
        int potion;
        cin>>potion;
        health+=potion;
        min_heap.push(potion);
        while(health < 0){
            health -= min_heap.top();
            min_heap.pop();
        }
    }
    cout << min_heap.size() <<'\n';

  return 0;
}

