// problem link: https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> mp;
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;

        int ans = 0;
        for(int i=0; i<s.length(); i++){
            if(i+1 < s.length() && mp.count(string("") + s[i] + s[i+1]) != 0){
                ans += mp[string("") + s[i] + s[i+1]];
                i++;
            }
            else
                ans+= mp[string("") + s[i]];
        }
        return ans;
    }
};
