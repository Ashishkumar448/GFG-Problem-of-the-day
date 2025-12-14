class Solution:
    def prefixSum2D(self, mat, queries):
        n = len(mat)
        m = len(mat[0])

        # Prefix sum with 1-based indexing
        pre = [[0] * (m + 1) for _ in range(n + 1)]

        for i in range(1, n + 1):
            row = mat[i - 1]
            pre_i = pre[i]
            pre_im1 = pre[i - 1]
            for j in range(1, m + 1):
                pre_i[j] = (row[j - 1]
                            + pre_im1[j]
                            + pre_i[j - 1]
                            - pre_im1[j - 1])

        ans = []

        for r1, c1, r2, c2 in queries:
            r1 += 1; c1 += 1; r2 += 1; c2 += 1

            s = (pre[r2][c2]
                 - pre[r1 - 1][c2]
                 - pre[r2][c1 - 1]
                 + pre[r1 - 1][c1 - 1])

            ans.append(s)

        return ans
