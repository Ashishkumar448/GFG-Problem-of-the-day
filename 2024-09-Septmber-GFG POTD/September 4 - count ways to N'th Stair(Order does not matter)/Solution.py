class Solution:
    def nthStair(self, n: int) -> int:
        # As order does not matter, we only need to count distinct combinations
        # For a given n, the result is (n // 2) + 1
        return (n // 2) + 1

# Driver code
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.nthStair(n)
        print(ans)
