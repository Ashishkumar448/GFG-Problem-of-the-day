from typing import List

class Solution:
    MAX = 10000

    def cntCoprime(self, arr: List[int]) -> int:
        freq = [0] * (self.MAX + 1)
        for num in arr:
            freq[num] += 1

        cnt = [0] * (self.MAX + 1)
        for d in range(1, self.MAX + 1):
            for multiple in range(d, self.MAX + 1, d):
                cnt[d] += freq[multiple]

        mobius = self.mobius_sieve(self.MAX)

        result = 0
        for d in range(1, self.MAX + 1):
            if mobius[d] == 0:
                continue
            c = cnt[d]
            result += mobius[d] * c * (c - 1) // 2

        return result

    def mobius_sieve(self, n: int) -> List[int]:
        mu = [1] * (n + 1)
        is_prime = [True] * (n + 1)

        for i in range(2, n + 1):
            if is_prime[i]:
                for j in range(i, n + 1, i):
                    mu[j] *= -1
                    is_prime[j] = False
                square = i * i
                for j in range(square, n + 1, square):
                    mu[j] = 0

        return mu
