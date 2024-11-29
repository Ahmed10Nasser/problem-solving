// problem link: https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0; i<flowerbed.size() && n; i++){
            if(flowerbed[i] == 1) continue;
            if((i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0)){
                n--;
                flowerbed[i] = 1;
            }
        }
        return n == 0;
    }
};