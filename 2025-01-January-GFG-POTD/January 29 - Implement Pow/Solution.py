class Solution:
    def power(self, b: float, e: int) -> float:
        # Base cases
        if e == 0:
            return 1.0  # Anything raised to the power 0 is 1
        if e < 0:
            return 1 / self.power(b, -e)  # Handle negative exponents
        
        # Recursive relation
        half = self.power(b, e // 2)  # Divide the problem
        if e % 2 == 0:
            return half * half  # If even, multiply the half result
        else:
            return half * half * b  # If odd, multiply an additional base

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        b, e = map(float, input().split())
        e = int(e)  # Convert exponent to integer
        ob = Solution()
        print(f"{ob.power(b, e):.5f}")
        print("~")
s
