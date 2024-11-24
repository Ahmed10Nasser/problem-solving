# problem link: https://leetcode.com/problems/maximum-matrix-sum/

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        min_value = (1e5) + 1
        sum = 0
        negative_count = 0
        for row in matrix:
            for val in row:
                if val < 0:
                    negative_count += 1
                min_value = min(min_value, abs(val))
                sum += abs(val)
        
        if negative_count % 2 == 0:
            return sum
        return sum - 2 * min_value