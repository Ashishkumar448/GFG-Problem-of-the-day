class Solution:
    def longestCommonSum(self, a1, a2):
        n = len(a1)
        prefix_sum = 0
        max_len = 0
        seen = {}

        for i in range(n):
            diff = a1[i] - a2[i]
            prefix_sum += diff

            if prefix_sum == 0:
                max_len = i + 1

            if prefix_sum in seen:
                max_len = max(max_len, i - seen[prefix_sum])
            else:
                seen[prefix_sum] = i

        return max_len
