// Problem Link: https://leetcode.com/problems/count-good-triplets/


class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans=0;
        int mx=*max_element(arr.begin(), arr.end());
        vector<int>cumlative_freq(mx+1, 0);
        for(int j=arr.size()-1; j>0; j--){
            for(int i=0; i<j; i++){
                if(abs(arr[i]-arr[j]) > a) continue;
                int lk = max({0, arr[j]-b, arr[i]-c});
                int rk = min({mx, arr[j]+b, arr[i]+c});
                if(lk > rk) continue;
                if(lk==0)
                    ans += cumlative_freq[rk];
                else
                    ans += cumlative_freq[rk] - cumlative_freq[lk-1];
            }

            for(int num=arr[j]; num<=mx; num++)
                cumlative_freq[num]++;
        }
        return ans;
    }
};