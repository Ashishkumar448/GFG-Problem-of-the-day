from bisect import bisect_left, bisect_right
from collections import defaultdict

class Solution:
    def countXInRange(self, arr, queries):
        result = []

        # Step 1: Preprocess positions
        mp = defaultdict(list)
        for i, val in enumerate(arr):
            mp[val].append(i)

        # Step 2: Answer queries
        for l, r, x in queries:
            if x not in mp:
                result.append(0)
                continue

            indices = mp[x]
            left = bisect_left(indices, l)
            right = bisect_right(indices, r)

            result.append(right - left)

        return result
