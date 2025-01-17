// problem link: https://leetcode.com/problems/bag-of-tokens/



class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int max_score = 0, curr_score = 0, l=0, r=tokens.size()-1;
        while(l<=r){
            if(power >= tokens[l]){
                power -= tokens[l];
                curr_score++;
                max_score = max(max_score, curr_score);
                l++;
            }
            else if(curr_score >= 1){
                curr_score--;
                power += tokens[r];
                r--;
            }
            else
                break;
        }
        return max_score;
    }
};