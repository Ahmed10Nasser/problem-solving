// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int max_day = prices.back();
        for(int i=prices.size()-2; i>=0; i--){
            max_profit = max(max_profit, max_day - prices[i]);
            max_day = max(max_day, prices[i]);
        }
        return max_profit;
    }
};
