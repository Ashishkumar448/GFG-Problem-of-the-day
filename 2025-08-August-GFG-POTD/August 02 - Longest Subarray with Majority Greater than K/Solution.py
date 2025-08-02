class Solution:
    def longestSubarray(self, arr, k):
        n = len(arr)
        transformed = [1 if x > k else -1 for x in arr]

        first_index = {}
        max_len = 0
        prefix_sum = 0

        for i in range(n):
            prefix_sum += transformed[i]

            if prefix_sum > 0:
                max_len = i + 1
            else:
                if prefix_sum not in first_index:
                    first_index[prefix_sum] = i

                if (prefix_sum - 1) in first_index:
                    prev_index = first_index[prefix_sum - 1]
                    max_len = max(max_len, i - prev_index)

        return max_len
