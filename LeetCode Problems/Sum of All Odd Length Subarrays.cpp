// Problem Link: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        for(int i=0; i<arr.size(); i++){
            int freq=0;
            for(int len=1; len<=arr.size(); len+=2){
                int l= max(0, i-(len-1));
                int r= min((int)arr.size()-1, i+(len-1));
                int sz=r-l+1;
                freq+= sz-len+1;
            }
            ans+= (freq * arr[i]);
        }
        return ans;
    }
};