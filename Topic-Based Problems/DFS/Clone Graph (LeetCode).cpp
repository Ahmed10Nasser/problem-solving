// Problem Link : https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
  void DFS(Node* node, unordered_set<Node*>& vis){
    if(node==NULL) return;
    vis.insert(node);
    for(auto& neigh : node->neighbors)
      if(vis.find(neigh)==vis.end())
        DFS(neigh, vis);
  }
public:
  Node* cloneGraph(Node* node) {
      unordered_set<Node*> vis;
      DFS(node, vis);
      int n=vis.size();
      vector<Node*> newGraph(n);
      for(int i=0; i<n; i++) newGraph[i]= new Node(i+1);
      for(auto& originalNode : vis)
        for(auto& originalNeigh : originalNode->neighbors)
          newGraph[originalNode->val - 1]->neighbors.push_back(newGraph[originalNeigh->val -1]);
      if(n==0) return NULL;
      return newGraph[node->val -1];
  }
};
