from typing import List
from collections import defaultdict

class Solution:
    def countBalanced(self, arr: List[str]) -> int:
        vowels = set('aeiou')
        balance_count = defaultdict(int)
        balance_count[0] = 1  # Base case for prefix balance

        balance = 0
        result = 0

        for s in arr:
            for ch in s:
                if ch in vowels:
                    balance += 1
                else:
                    balance -= 1
            result += balance_count[balance]
            balance_count[balance] += 1

        return result
