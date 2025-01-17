// problem link: https://leetcode.com/problems/first-bad-version/


class Solution {
public:
    int firstBadVersion(int n) {
        int l=1, r=n;
        while(l < r){
            int mid = ((long long)l+r)/2;
            if(isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};