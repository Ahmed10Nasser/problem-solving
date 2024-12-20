// problem link: https://leetcode.com/problems/happy-number/


class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long>st;
        while(n != 1){
            st.insert(n);
            string s = to_string(n);
            long long next_n = 0;
            for(auto& ch : s){
                int d= ch-'0';
                next_n += (d*d);
            }
            if(st.count(next_n) > 0)
                return false;
            n = next_n; 
        }
        return true;
    }
};