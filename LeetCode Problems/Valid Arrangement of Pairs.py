# problem link: https://leetcode.com/problems/valid-arrangement-of-pairs/

class Solution:
    def DFS(self,
            node: int,
            adjs: dict[int, list[int]],
            outdegree: dict[int,int],
            path: list[int]):
        while outdegree.get(node, 0) > 0:            
            outdegree[node] -= 1
            neigh = adjs[node][outdegree[node]]
            self.DFS(neigh, adjs, outdegree, path)
        path.append(node)
    
    def Euler(self,
              adjs: dict[int, list[int]],
              edges: int,
              nodes: set[int],
              indegree: dict[int,int],
              outdegree: dict[int,int]):
        start = 0
        end = 0
        for node in nodes:
            if abs(outdegree.get(node, 0) - indegree.get(node, 0)) > 1:
                return []
            if outdegree.get(node, 0) - indegree.get(node, 0) == 1:
                start += 1
            elif indegree.get(node, 0) - outdegree.get(node, 0) == 1:
                end += 1
        if not ((start==0 and end==0) or (start==1 and end==1)):
            return []

        path = []
        for node in nodes:
            if (start==0 and outdegree.get(node, 0) > 0) \
                    or (start==1 and outdegree.get(node, 0) - indegree.get(node, 0) == 1):
                self.DFS(node, adjs, outdegree, path)
                break
        if len(path) != edges+1:
            return []
        path.reverse()
        return path

    def validArrangement(self, pairs: list[list[int]]) -> list[list[int]]:
        adjs = dict()
        nodes = set()
        indegree = dict()
        outdegree = dict()
        for pair in pairs:
            nodes.add(pair[0])
            nodes.add(pair[1])
            if pair[0] in adjs:
                adjs[pair[0]].append(pair[1])
            else:
                adjs[pair[0]] = [pair[1]]
            indegree[pair[1]] = indegree.get(pair[1], 0) + 1
            outdegree[pair[0]] = outdegree.get(pair[0], 0) + 1

        path = self.Euler(adjs, len(pairs), nodes, indegree, outdegree)
        if not path:
            return []
        ans = []
        for i in range(1,len(path)):
            ans.append([path[i-1], path[i]])
        return ans