class Solution:
    @staticmethod
    def subsetXOR(n: int):
        ans = []
        
        # XOR of 1 to n
        t = 0
        for i in range(1, n + 1):
            t ^= i
        
        # Case 1: XOR already equals n → include all
        if t == n:
            return list(range(1, n + 1))
        
        x = t ^ n  # value to remove if possible
        
        # Case 2: removing a single number x works
        if 1 <= x <= n:
            return [i for i in range(1, n + 1) if i != x]
        
        # Case 3: need to remove two numbers a and b with a ^ b = x
        a = b = -1
        for i in range(n, 0, -1):
            j = i ^ x
            if 1 <= j <= n and j != i:
                a = i
                b = j
                break
        
        return [i for i in range(1, n + 1) if i != a and i != b]
