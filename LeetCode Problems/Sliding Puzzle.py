# problem link: https://leetcode.com/problems/sliding-puzzle/

from queue import Queue

class Solution:
    @staticmethod
    def swap(s: str, index1: int, index2: int) -> str:
        l = list(s)
        l[index1], l[index2] = l[index2], l[index1]
        return "".join(l)
    
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        target_state = "123450"
        directions = [[1,3], [0,2,4], [1,5], [0,4], [1,3,5], [2,4]]
        dis_map = dict()
        queue = Queue()
        start_state = ""
        for row in board:
            for val in row:
                start_state += str(val)
        dis_map[start_state] = 0
        queue.put(start_state)

        while not queue.empty():
            curr_state = queue.get()
            if curr_state == target_state:
                return dis_map[curr_state]
            zero_index = curr_state.find("0")
            for dir in directions[zero_index]:
                next_state = self.swap(curr_state, zero_index, dir)
                if dis_map.get(next_state) is None:
                    dis_map[next_state] = dis_map[curr_state] + 1
                    queue.put(next_state)
        return -1
        