class Solution:
    def nonLisMaxSum(self, arr):
        n = len(arr)
        dp_len = [1] * n
        dp_sum = arr[:]

        for i in range(1, n):
            for j in range(i):
                if arr[j] < arr[i]:
                    if dp_len[j] + 1 > dp_len[i]:
                        dp_len[i] = dp_len[j] + 1
                        dp_sum[i] = dp_sum[j] + arr[i]
                    elif dp_len[j] + 1 == dp_len[i]:
                        dp_sum[i] = min(dp_sum[i], dp_sum[j] + arr[i])

        max_len = max(dp_len)
        min_sum = float('inf')

        for i in range(n):
            if dp_len[i] == max_len:
                min_sum = min(min_sum, dp_sum[i])

        total_sum = sum(arr)
        return total_sum - min_sum
