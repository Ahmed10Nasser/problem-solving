// problem link: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/


class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target_arrival_time = times[targetFriend][0];
        sort(times.begin(), times.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> current_seats;
        priority_queue<int, vector<int>, greater<int>> empty_seats;
        int next_seat = 0;
        for(auto& time : times){
            int arrvial_time = time[0], leaving_time = time[1];
            while(!current_seats.empty() && current_seats.top().first <= arrvial_time){
                int seat_number = current_seats.top().second;
                empty_seats.push(seat_number);
                current_seats.pop();
            }
            int curr_seat_number;
            if(!empty_seats.empty()){
                curr_seat_number = empty_seats.top();
                empty_seats.pop();
            }
            else{
                curr_seat_number = next_seat;
                next_seat++;
            }
            if(arrvial_time == target_arrival_time) return curr_seat_number;
            current_seats.push({leaving_time, curr_seat_number});
        }
        return 0;
    }
};