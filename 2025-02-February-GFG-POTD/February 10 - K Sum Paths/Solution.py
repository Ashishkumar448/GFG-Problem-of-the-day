class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def sumK(self, root, k):
        # Dictionary to store prefix sums and their frequencies
        prefix_sum_map = {0: 1}  # Base case: sum 0 exists once
        return self.findPaths(root, 0, k, prefix_sum_map)

    def findPaths(self, node, curr_sum, k, prefix_sum_map):
        if not node:
            return 0

        # Update the current prefix sum
        curr_sum += node.data

        # Count the number of times (curr_sum - k) has occurred
        count = prefix_sum_map.get(curr_sum - k, 0)

        # Store the current sum in the map
        prefix_sum_map[curr_sum] = prefix_sum_map.get(curr_sum, 0) + 1

        # Recur for left and right children
        count += self.findPaths(node.left, curr_sum, k, prefix_sum_map)
        count += self.findPaths(node.right, curr_sum, k, prefix_sum_map)

        # Backtrack: Remove the current sum before returning to the parent node
        prefix_sum_map[curr_sum] -= 1

        return count
