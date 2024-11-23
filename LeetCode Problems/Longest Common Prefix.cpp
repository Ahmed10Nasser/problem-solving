// problem link: https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0; i<strs[0].length(); i++){
            bool all_match = true;
            for(int j=1; j<strs.size(); j++){
                if(i >= strs[j].length() || strs[j][i] != strs[0][i]){
                    all_match = false;
                    break;
                }
            }
            if(all_match) ans+=strs[0][i];
            else break;
        }
        return ans;
    }
};