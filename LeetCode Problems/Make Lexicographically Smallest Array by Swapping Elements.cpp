// Problem Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/


class Solution {
private:
    int findParent(int node, vector<int>& par){
        if(par[node] == node) return node;
        return par[node] = findParent(par[node], par);
    }

    void join(int node1, int node2, vector<int>&par, vector<priority_queue<int,vector<int>, greater<int>>>& dsu){
        node1 = findParent(node1, par);
        node2 = findParent(node2, par);
        if(node1 == node2) return;
        if(dsu[node2].size() > dsu[node1].size()) swap(node1, node2);
        par[node2] = node1;
        while (!dsu[node2].empty()){
            dsu[node1].push(dsu[node2].top());
            dsu[node2].pop();
        }
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>par(nums.size());
        vector<priority_queue<int,vector<int>, greater<int>>> dsu(nums.size());
        for(int i=0; i<nums.size(); i++){
            par[i] = i;
            dsu[i].push(nums[i]);
        }
        vector<pair<int,int>>arr;
        for(int i=0; i<nums.size(); i++)
            arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size()-1; i++)
            if(arr[i+1].first - arr[i].first <= limit)
                join(arr[i].second, arr[i+1].second, par, dsu);
        vector<int>ans(nums.size());
        for(int i=0; i<nums.size(); i++){
            int parent = findParent(i, par);
            ans[i] = dsu[parent].top();
            dsu[parent].pop();
        }
        return ans;
    }
};