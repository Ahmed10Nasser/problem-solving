// problem link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/


class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=0; i<nums.size(); i++){
            int x=i+1;
            if(nums[i] >= x && (i==nums.size()-1 || nums[i+1] < x))
                return x;
        }
        return -1;
    }
};
