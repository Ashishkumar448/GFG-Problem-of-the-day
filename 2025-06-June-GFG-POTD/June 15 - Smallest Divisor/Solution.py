class Solution:
    def smallestDivisor(self, arr, k):
        def get_sum(divisor):
            return sum((num + divisor - 1) // divisor for num in arr)

        left, right = 1, max(arr)
        answer = right

        while left <= right:
            mid = (left + right) // 2
            if get_sum(mid) <= k:
                answer = mid
                right = mid - 1
            else:
                left = mid + 1

        return answer
