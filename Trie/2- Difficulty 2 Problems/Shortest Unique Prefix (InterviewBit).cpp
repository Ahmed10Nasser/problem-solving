// Problem Link : https://www.interviewbit.com/problems/shortest-unique-prefix/

class Trie{
  private:

  struct Node{
    unordered_map<char,Node*>childern={};
    int usedCount=0;
  };

  Node* root=NULL;

  public:

  Trie(){
    root= new Node;
  }

  void add(string& s){
    Node* node=root;
    for(auto& ch : s){
      if(node->childern.find(ch)==node->childern.end()) node->childern[ch]=new Node;
      node=node->childern[ch];
      node->usedCount++;
    }
  }
  
  string getUniquePrefix(string& s){
      Node* node=root;
      string ret="";
      for(auto& ch : s){
          node=node->childern[ch];
          ret+=ch;
          if(node->usedCount==1) break;
      }
      return ret;
  }  

};



vector<string> Solution::prefix(vector<string> &A) {
    Trie trie=Trie();
    for(auto& s : A) trie.add(s);
    vector<string> ans;
    for(auto& s : A) ans.push_back(trie.getUniquePrefix(s));
    return ans;
}
