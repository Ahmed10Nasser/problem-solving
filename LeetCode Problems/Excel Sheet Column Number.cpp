// Problem Link : https://leetcode.com/problems/excel-sheet-column-number/


class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());
        int ans = 0;
        long long pow_of_26 = 1;
        for(auto& ch : columnTitle){
            ans += (pow_of_26 * (ch - 'A' +1)); 
            pow_of_26 *= 26;
        }
        return ans;
    }
};
