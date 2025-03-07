// Problem Link: https://leetcode.com/problems/xor-queries-of-a-subarray/description/



class Solution {
    public:
        vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
            vector<int> prefix_xor(arr.size(), 0);
            prefix_xor[0] = arr[0];
            for(int i=1; i<arr.size(); i++)
                prefix_xor[i] = prefix_xor[i-1] ^ arr[i];
            
            vector<int>ans;
            for(auto& query : queries){
                int l=query[0], r=query[1];
                if(l==0) ans.push_back(prefix_xor[r]);
                else ans.push_back(prefix_xor[r] ^ prefix_xor[l-1]);
            }

            return ans;
        }
};