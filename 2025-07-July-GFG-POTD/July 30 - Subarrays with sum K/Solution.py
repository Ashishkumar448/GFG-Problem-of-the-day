from collections import defaultdict

class Solution:
    def cntSubarrays(self, arr, k):
        prefix_sum_count = defaultdict(int)
        prefix_sum_count[0] = 1

        prefix_sum = 0
        count = 0

        for num in arr:
            prefix_sum += num
            count += prefix_sum_count[prefix_sum - k]
            prefix_sum_count[prefix_sum] += 1

        return count
