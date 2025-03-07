// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/description/


class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int l=1, r=nums.size()-1;
            while(l < r){
                int mid=(l+r)/2;
                int cnt=0;
                for(auto& num : nums)
                    if(num <= mid)
                        cnt++;
                if(cnt <= mid)
                    l = mid + 1;
                else
                    r = mid;
            }
            return l;
        }
};