// Problem Link: https://www.spoj.com/problems/ADAQUEUE/en/

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
    deque<int>dq;
    unordered_map<string, string> inv;
    inv["back"]="front";
    inv["front"]="back";
    inv["push_back"]="toFront";
    inv["toFront"]="push_back";
    inv["reverse"] = "reverse";
    int q, dir=1;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(dir == -1) s = inv[s];

        if(s == "reverse") dir *= -1;
        else if(s == "front"){
            if(dq.empty()) cout<<"No job for Ada?\n";
            else{
                cout<<dq.front()<<'\n';
                dq.pop_front();
            }
        }
        else if(s == "back"){
            if(dq.empty()) cout<<"No job for Ada?\n";
            else{
                cout<<dq.back()<<'\n';
                dq.pop_back();
            }
        }
        else if(s=="push_back"){
            int num;
            cin>>num;
            dq.push_back(num);
        }
        else{
            int num;
            cin>>num;
            dq.push_front(num);
        }
    }

  return 0;
}
