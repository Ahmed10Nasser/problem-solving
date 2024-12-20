// problem link: https://atcoder.jp/contests/abc217/tasks/abc217_e

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

    int q;
    cin>>q;
    deque<int> dq;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int x;
            cin>>x;
            dq.push_back(x);
        }
        else if(type == 2){
            if(!min_heap.empty()){
                cout<< min_heap.top() <<'\n';
                min_heap.pop();
            }
            else{
                cout<<dq.front() <<'\n';
                dq.pop_front();
            }
        }
        else{
            while(!dq.empty()){
                min_heap.push(dq.back());
                dq.pop_back();
            }
        }
    }

  return 0;
}

