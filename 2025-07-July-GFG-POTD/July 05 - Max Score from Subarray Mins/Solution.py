class Solution:
    def maxSum(self, arr):
        max_score = 0
        for i in range(len(arr) - 1):
            s = arr[i] + arr[i + 1]
            if s > max_score:
                max_score = s
        return max_score
