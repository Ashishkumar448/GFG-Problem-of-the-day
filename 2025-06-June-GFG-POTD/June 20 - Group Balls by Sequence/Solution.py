from collections import Counter
from typing import List

class Solution:
    def validgroup(self, arr: List[int], k: int) -> bool:
        if len(arr) % k != 0:
            return False

        freq = Counter(arr)
        for num in sorted(freq):
            while freq[num] > 0:
                for i in range(k):
                    current = num + i
                    if freq[current] == 0:
                        return False
                    freq[current] -= 1

        return True
