# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.left = None
#         self.right = None

class Solution:
    def countAllPaths(self, root, k):
        from collections import defaultdict
        
        mp = defaultdict(int)
        mp[0] = 1  # base case
        
        def dfs(node, curr_sum):
            if not node:
                return 0
            
            curr_sum += node.data
            
            count = mp[curr_sum - k]
            
            mp[curr_sum] += 1
            
            count += dfs(node.left, curr_sum)
            count += dfs(node.right, curr_sum)
            
            mp[curr_sum] -= 1  # backtrack
            
            return count
        
        return dfs(root, 0)
