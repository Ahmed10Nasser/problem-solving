// problem link: https://codeforces.com/problemset/problem/339/A

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
    string s;
    cin>>s;
    vector<int>freq(4, 0);
    for(int i=0; i<s.length(); i+=2)
        freq[s[i] - '0']++;
    
    vector<int>ans;
    for(int val=1; val<=3; val++)
        while(freq[val]--)
            ans.push_back(val);
    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
        if(i != ans.size()-1) cout<<'+';
    }
    cout<<'\n';


    return 0;
}

