# problem link: https://leetcode.com/problems/find-champion-ii/

class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        in_degree = [0] * n
        for edge in edges:
            in_degree[edge[1]] += 1
        ans = -1
        for node in range(n):
            if in_degree[node] == 0:
                if ans == -1:
                    ans = node
                else:
                    return -1
        return ans
        