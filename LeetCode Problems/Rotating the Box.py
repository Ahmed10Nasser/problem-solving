# problem link: https://leetcode.com/problems/rotating-the-box/

class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        rows = len(box)
        cols = len(box[0])
        sum_arr = [[0]*(cols+1) for _ in range(rows)]
        for row in range(rows):
            sum = 0
            for col in range(cols+1):
                if col < cols and box[row][col] == '#':
                    sum+=1
                elif col == cols or box[row][col] == '*':
                    sum_arr[row][col] = sum
                    sum = 0
        ans = [['.']*rows for _ in range(cols)]
        for row in range(rows):
            sum = sum_arr[row][cols]
            for col in range(cols-1, -1, -1):
                ch = '.'
                if box[row][col] == '*':
                    ch = '*'
                    sum = sum_arr[row][col]
                elif sum > 0:
                    ch = '#'
                    sum = sum - 1
                ans[col][rows-1-row] = ch
        return ans
