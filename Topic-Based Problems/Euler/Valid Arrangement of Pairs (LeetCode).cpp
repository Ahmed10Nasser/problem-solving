// problem link: https://leetcode.com/problems/valid-arrangement-of-pairs/

class Solution {
private:
    void DFS(int node, unordered_map<int, vector<int>>& adj, unordered_map<int,int>& out_degree, vector<int>& path){
        while(out_degree[node] > 0){
            auto neigh = adj[node][--out_degree[node]];
            DFS(neigh, adj, out_degree, path);
        }
        path.push_back(node);
    }
    vector<int> Euler(unordered_map<int, vector<int>>& adj, int edges,
    unordered_map<int,int>& in_degree, unordered_map<int,int>& out_degree,
    unordered_set<int>& nodes){
        int start=0, end=0;
        for(auto& node : nodes){
            if(abs(in_degree[node] - out_degree[node]) > 1) return {};
            if(out_degree[node] - in_degree[node] == 1) start++;
            else if(in_degree[node] - out_degree[node] == 1) end++;
        }
        if(!((start==0 && end==0) || (start==1 && end==1))) return {};

        vector<int>path;
        for(auto& node : nodes){
            if((start==0 && out_degree[node] > 0) || (start==1 && out_degree[node] - in_degree[node] == 1)){
                DFS(node, adj, out_degree, path);
                break;
            }
        }
        if(path.size() != edges+1) return {};
        reverse(path.begin(), path.end());
        return path;

    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>>adj;
        unordered_map<int,int>in_degree, out_degree;
        unordered_set<int>nodes;
        for(auto& pair : pairs){
            adj[pair[0]].push_back(pair[1]);
            out_degree[pair[0]]++;
            in_degree[pair[1]]++;
            nodes.insert(pair[0]);
            nodes.insert(pair[1]);
        }
        auto path = Euler(adj, pairs.size(), in_degree, out_degree, nodes);
        if(path.empty()) return {};
        vector<vector<int>>ans;
        for(int i=1; i<path.size(); i++)
            ans.push_back({path[i-1], path[i]});
        return ans;
    }
};
