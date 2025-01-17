// problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int l=0, r=-1, max_len = 0;
        while(r+1 < s.length()){
            while(st.count(s[r+1])){
                st.erase(s[l]);
                l++;
            }
            r++;
            st.insert(s[r]);
            max_len = max(max_len, r-l+1);
        }
        return max_len;
    }
};