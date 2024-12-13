// problem link: https://leetcode.com/problems/time-needed-to-buy-tickets/


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0; i<tickets.size(); i++)
            q.push({i, tickets[i]});
        int time = 0;
        while(!q.empty()){
            int index = q.front().first;
            int rem = q.front().second;
            q.pop();
            rem--;
            time++;
            if(rem != 0) q.push({index, rem});
            else if(index == k) break;
        }
        return time;
    }
};