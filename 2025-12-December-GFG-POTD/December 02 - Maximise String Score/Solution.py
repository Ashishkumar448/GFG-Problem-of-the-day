class Solution:
    def maxScore(self, s: str, jumps: List[List[str]]) -> int:
        if not s:
            return 0

        ALPHA = 26
        n = len(s)
        a = list(s)

        # allowed transitions
        allowed = [[False] * ALPHA for _ in range(ALPHA)]
        for i in range(ALPHA):
            allowed[i][i] = True
        for p in jumps:
            if len(p) < 2:
                continue
            from_c, to_c = p[0], p[1]
            if 'a' <= from_c <= 'z' and 'a' <= to_c <= 'z':
                allowed[ord(from_c) - 97][ord(to_c) - 97] = True

        # prefix sums
        prefTotal = [0] * (n + 1)
        prefChar = [[0] * (n + 1) for _ in range(ALPHA)]

        for i in range(n):
            prefTotal[i + 1] = prefTotal[i] + ord(a[i])
            for c in range(ALPHA):
                prefChar[c][i + 1] = prefChar[c][i]
            ci = ord(a[i]) - 97
            if 0 <= ci < ALPHA:
                prefChar[ci][i + 1] += ord(a[i])

        NEG = -10**30
        bestTo = [NEG] * ALPHA
        dp = [NEG] * n

        dp[0] = 0
        for t in range(ALPHA):
            if allowed[ord(a[0]) - 97][t]:
                bestTo[t] = max(bestTo[t], dp[0] - prefTotal[0] + prefChar[t][0])

        ans = 0
        for j in range(1, n):
            t = ord(a[j]) - 97
            if bestTo[t] != NEG:
                cand = bestTo[t] + (prefTotal[j] - prefChar[t][j])
                dp[j] = cand
                if cand > ans:
                    ans = cand

            if dp[j] != NEG:
                for trg in range(ALPHA):
                    if allowed[ord(a[j]) - 97][trg]:
                        val = dp[j] - prefTotal[j] + prefChar[trg][j]
                        if val > bestTo[trg]:
                            bestTo[trg] = val

        return ans
