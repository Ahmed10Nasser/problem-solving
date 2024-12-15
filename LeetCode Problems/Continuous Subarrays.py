# problem link: https://leetcode.com/problems/continuous-subarrays/

from collections import deque

class Solution:
    def continuousSubarrays(self, nums: list[int]) -> int:
        max_q = deque()
        min_q = deque()
        left = 0
        ans = 0
        for right, num in enumerate(nums):
            while max_q and nums[max_q[-1]] < num:
                max_q.pop()
            max_q.append(right)
            while min_q and nums[min_q[-1]] > num:
                min_q.pop()
            min_q.append(right)
            
            while max_q and min_q and nums[max_q[0]] - nums[min_q[0]] > 2:
                if max_q[0] < min_q[0]:
                    left = max_q[0] + 1
                    max_q.popleft()
                else:
                    left = min_q[0] + 1
                    min_q.popleft()
            
            ans += right - left + 1 
        
        return ans