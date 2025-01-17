// problem link: https://leetcode.com/problems/koko-eating-bananas/


class Solution {
private:
    bool check(int k, int h, vector<int>& piles){
        int taken_h = 0;
        for(auto& pile : piles)
            taken_h += ((pile + k - 1)/k);
        return taken_h <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());
        while(l < r){
            int mid=(l+r)/2;
            if(check(mid, h, piles)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};