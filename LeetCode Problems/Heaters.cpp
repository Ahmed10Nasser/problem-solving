// problem link: https://leetcode.com/problems/heaters/


// solution 1
class Solution {
private:
    bool check(int radius, vector<int>& houses, vector<int>& heaters){
        for(auto& house : houses){
            int l=house-radius, r=house+radius;
            int index = lower_bound(heaters.begin(), heaters.end(), l) - heaters.begin();
            if(index >= heaters.size() || heaters[index] > r) return false;
        }
        return true;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int l=0, r=(1e9)-1;
        while(l < r){
            int mid=(l+r)/2;
            if(check(mid, houses, heaters)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

// solution 2
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for(auto& house : houses){
            int right_heater = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int left_heater = right_heater - 1;
            int min_raduis = 1e9;
            if(right_heater < heaters.size()) min_raduis = min(min_raduis, heaters[right_heater] - house);
            if(left_heater >= 0) min_raduis = min(min_raduis, house - heaters[left_heater]);
            ans = max(ans, min_raduis);
        }
        return ans;
    }
};