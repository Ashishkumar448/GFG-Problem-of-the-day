class Solution:
    def maxKPower(self, n: int, k: int) -> int:
        # Factorize k into its prime factors
        prime_factors = {}
        num = k
        i = 2
        while i * i <= num:
            while k % i == 0:
                prime_factors[i] = prime_factors.get(i, 0) + 1
                k //= i
            i += 1
        if k > 1:
            prime_factors[k] = prime_factors.get(k, 0) + 1

        # Apply Legendre's formula
        result = float('inf')
        for p, a in prime_factors.items():
            count = 0
            temp = n
            while temp > 0:
                temp //= p
                count += temp
            result = min(result, count // a)

        return result
