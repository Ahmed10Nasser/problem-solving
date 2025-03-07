// Problem Link: https://leetcode.com/problems/single-number/description/


class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int single_number = 0;
            for(auto& num : nums) single_number = single_number ^ num;
            return single_number;
        }
};