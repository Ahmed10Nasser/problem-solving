# problem link: https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution:
    def checkIfExist(self, arr: list[int]) -> bool:
        freq = dict()
        for num in arr:
            freq[num] = freq.get(num, 0) + 1
        for num in arr:
            if freq.get(2*num, 0) > int(num==0):
                return True
        return False
        