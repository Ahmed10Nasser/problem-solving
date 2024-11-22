class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long mx1=INT_MIN-1LL, mx2=INT_MIN-1LL, mx3=INT_MIN-1LL;
        for(auto num : nums){
            if(num > mx1){
                mx3 = mx2;
                mx2 = mx1;
                mx1 = num;
            }
            else if(num > mx2 && num != mx1){
                mx3 = mx2;
                mx2 = num;
            }
            else if(num > mx3 && num != mx2 && num != mx1){
                mx3 = num;
            }
        }
        if(mx3 == INT_MIN-1LL)
            return mx1;
        return mx3;
    }
};