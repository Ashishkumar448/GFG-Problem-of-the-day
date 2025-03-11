class Solution:
    def countWays(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2

        prev2, prev1 = 1, 2
        curr = 0

        for _ in range(3, n + 1):
            curr = prev1 + prev2
            prev2 = prev1
            prev1 = curr

        return curr


if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        n = int(input())  # Number of stairs
        obj = Solution()
        print(obj.countWays(n))
        print("~")
