// Problem Link : https://leetcode.com/problems/search-insert-position/


// solution 1
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

// solution 2
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size();
        while(l < r){
            int mid=(l+r)/2;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};