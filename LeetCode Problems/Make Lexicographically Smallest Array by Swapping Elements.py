# Problem Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/

import heapq

class Solution:
    def findParent(self, node: int, par: list[int]):
        if par[node] == node:
            return node
        par[node] = self.findParent(par[node], par)
        return par[node]

    def join(self, node1: int, node2: int, par: list[int], dsu: list[list[int]]):
        node1 = self.findParent(node1, par)
        node2 = self.findParent(node2, par)
        if node1 == node2:
            return
        if len(dsu[node2]) > len(dsu[node1]):
            node1, node2 = node2, node1
        par[node2] = node1
        while len(dsu[node2]) > 0:
            heapq.heappush(dsu[node1], heapq.heappop(dsu[node2]))
        

    def lexicographicallySmallestArray(self, nums: list[int], limit: int) -> list[int]:
        par = [i for i in range(len(nums))]
        dsu = [[num] for num in nums]
        arr = [(num, i) for i,num in enumerate(nums)]
        arr.sort()
        for i in range(len(nums)-1):
            if arr[i+1][0] - arr[i][0] <= limit:
                self.join(arr[i][1], arr[i+1][1], par, dsu)
        ans = []
        for i in range(len(nums)):
            parent = self.findParent(i, par)
            ans.append(heapq.heappop(dsu[parent]))
        return ans