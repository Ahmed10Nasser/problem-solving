// Problem Link : https://vjudge.net/problem/SPOJ-PHONELST

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

class Trie{
private:
  struct Node{
    unordered_map<char,Node*>childern={};
    bool isLeaf=true;
    int count=0;      
  };

  Node* root=NULL;

public:
  Trie(){
    root = new Node;
  }

  void add(string& s){
    Node* node=root;
    for(auto& ch : s){
      if(node->childern.find(ch) == node->childern.end()){
        node->childern[ch] = new Node;
        node->isLeaf=false;
      }
      node = node->childern[ch];
      node->count++;
    }
  }

  int countPrefixes(string& s){
    Node* node=root;
    for(auto& ch : s){
      if(node->childern.find(ch) == node->childern.end()) return 0;
      node = node->childern[ch];
    }
    return node->count;    
  }
};


int main(){
  FIO 
  // freopen("input.txt","rt",stdin);
  // freopen("output.txt","wt",stdout);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    Trie trie=Trie();
    vector<string>arr(n);
    for(auto& s : arr){
      cin>>s;
      trie.add(s);
    }
    bool ans=1;
    for(auto& s : arr){
      if(trie.countPrefixes(s) > 1){
        ans=0;
        break;
      }
    }
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
  }

  return 0;
} 



