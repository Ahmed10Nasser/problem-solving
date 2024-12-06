// problem link: https://leetcode.com/problems/sort-array-by-parity/


class Solution {
    static bool comp(int a, int b){
        if(a%2 == b%2) return a>=b;
        return a%2 == 0;
    }

public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        return nums;
    }
};