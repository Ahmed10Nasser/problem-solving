class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        nums_map = dict()
        sum = max_sum = 0
        for i in range(len(nums)):
            if i >= k:
                nums_map[nums[i-k]] -= 1
                if nums_map[nums[i-k]] == 0:
                    nums_map.pop(nums[i-k])
                sum -= nums[i-k]
            nums_map[nums[i]] = nums_map.get(nums[i], 0) + 1
            sum += nums[i]
            if len(nums_map) == k:
                max_sum = max(max_sum, sum)
        return max_sum