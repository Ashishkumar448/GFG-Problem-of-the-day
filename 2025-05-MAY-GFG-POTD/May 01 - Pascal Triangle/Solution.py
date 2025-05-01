MOD = 1000000007

class Solution:
    def nthRowOfPascalTriangle(self, n):
        row = []
        val = 1
        row.append(val)

        for k in range(1, n):
            val = val * (n - k)
            val = val // k
            val = val % MOD
            row.append(val)

        return row

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        sol = Solution()
        ans = sol.nthRowOfPascalTriangle(n)
        print(" ".join(map(str, ans)))
        print("~")
