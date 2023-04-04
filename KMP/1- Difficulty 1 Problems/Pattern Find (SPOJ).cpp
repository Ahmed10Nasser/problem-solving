// Problem Link : https://vjudge.net/problem/SPOJ-NAJPF

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;



vector<int> KMP(string& s){
  int n=s.length();
  vector<int>prefix(n);
  int border=0;
  prefix[0]=0;
  for(int i=1; i<n; i++){
    while(border > 0 && s[border] != s[i]) border=prefix[border-1];
    if(s[border] == s[i]) border++;
    prefix[i] = border;
  }
  return prefix;
}


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t;
  cin>>t;
  while(t--){
    string s,p;
    cin>>s>>p;
    int sz=p.length();
    string a=p+'#'+s;
    auto prefix=KMP(a);
    vector<int>ans;
    for(int i=sz+1; i<a.length(); i++)
      if(prefix[i]==sz)
        ans.push_back(i-2*sz);
    
    if(ans.empty())
      cout<<"Not Found\n\n";
    else{
      cout<<ans.size()<<'\n';
      for(auto& index : ans) cout<<index+1<<' ';
      cout<<"\n\n";
    }

  }

  return 0;
} 



