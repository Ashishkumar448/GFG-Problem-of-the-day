
from typing import List
from collections import defaultdict

class Solution:
    def powerfulInteger(self, intervals: List[List[int]], k: int) -> int:
        mp = defaultdict(int)

        # Mark start and end+1
        for start, end in intervals:
            mp[start] += 1
            mp[end + 1] -= 1

        curr = 0
        last_point = -1
        max_powerful = -1

        for point in sorted(mp):
            if curr >= k and last_point != -1:
                max_powerful = max(max_powerful, point - 1)
            curr += mp[point]
            last_point = point

        return max_powerful
