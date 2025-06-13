class Solution:
    def kokoEat(self, arr, k):
        left = 1
        right = max(arr)
        
        while left < right:
            mid = (left + right) // 2
            total = sum((num + mid - 1) // mid for num in arr)
            if total <= k:
                right = mid
            else:
                left = mid + 1
        return left
