// problem link: https://leetcode.com/problems/subarray-sum-equals-k/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq_of_sums;
        int prefix_sum = 0, ans = 0;
        freq_of_sums[0]++;
        for(auto& num : nums){
            prefix_sum += num;
            if(freq_of_sums.count(prefix_sum - k))
                ans += freq_of_sums[prefix_sum - k];
            freq_of_sums[prefix_sum]++;
        }
        return ans;
    }
};

