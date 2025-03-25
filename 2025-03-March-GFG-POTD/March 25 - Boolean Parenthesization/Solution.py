class Solution:
    def countWays(self, s: str) -> int:
        n = len(s)
        m = (n + 1) // 2  # Number of symbols (T/F)
        if m == 0:
            return 0

        T = [[0] * m for _ in range(m)]  # True counts
        F = [[0] * m for _ in range(m)]  # False counts

        # Base case: single symbol
        for i in range(m):
            if s[2 * i] == 'T':
                T[i][i] = 1
                F[i][i] = 0
            else:
                T[i][i] = 0
                F[i][i] = 1

        # Fill DP tables
        for length in range(2, m + 1):
            for i in range(m - length + 1):
                j = i + length - 1
                T[i][j] = 0
                F[i][j] = 0

                for k in range(i, j):
                    op = s[2 * k + 1]
                    leftT, leftF = T[i][k], F[i][k]
                    rightT, rightF = T[k + 1][j], F[k + 1][j]

                    if op == '&':
                        T[i][j] += leftT * rightT
                        F[i][j] += leftT * rightF + leftF * rightT + leftF * rightF
                    elif op == '|':
                        T[i][j] += leftT * rightT + leftT * rightF + leftF * rightT
                        F[i][j] += leftF * rightF
                    elif op == '^':
                        T[i][j] += leftT * rightF + leftF * rightT
                        F[i][j] += leftT * rightT + leftF * rightF

        return T[0][m - 1]


# Driver Code
if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        obj = Solution()
        print(obj.countWays(s))
        print("~")
