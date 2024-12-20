// problem link: https://leetcode.com/problems/contains-duplicate-iii/


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> st;
        for(int i=0; i<nums.size(); i++){
            auto insert_ret = st.insert(nums[i]);
            auto found = !(insert_ret.second);
            if(found) return true;
            auto it = insert_ret.first;
            if(it != st.begin() && nums[i] - (*prev(it)) <= valueDiff) return true;
            if(next(it) != st.end() && (*next(it)) - nums[i] <= valueDiff) return true;
            if(i>=indexDiff) st.erase(nums[i-indexDiff]);
        }
        return false;
    }
};