from collections import Counter

class Solution:
    def findGreater(self, arr):
        n = len(arr)
        res = []
        stack = []
        freq_map = Counter(arr)

        # Traverse from right to left
        for i in range(n - 1, -1, -1):
            curr = arr[i]

            while stack and freq_map[stack[-1]] <= freq_map[curr]:
                stack.pop()

            if not stack:
                res.append(-1)
            else:
                res.append(stack[-1])

            stack.append(curr)

        res.reverse()
        return res
