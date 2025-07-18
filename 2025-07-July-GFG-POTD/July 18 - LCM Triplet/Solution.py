class Solution:
    def lcmTriplets(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        if n == 3:
            return 6

        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        def lcm(a, b):
            return (a * b) // gcd(a, b)

        if n % 2 != 0:
            result = lcm(n, lcm(n - 1, n - 2))
        else:
            l1 = lcm(n, lcm(n - 1, n - 3))
            l2 = lcm(n, lcm(n - 1, n - 2))
            l3 = lcm(n - 1, lcm(n - 2, n - 3))
            result = max(l1, l2, l3)

        return result
