class Solution:
    def splitArray(self, arr, k):
        def can_split(arr, k, max_sum):
            current_sum = 0
            splits = 1
            for num in arr:
                if current_sum + num > max_sum:
                    splits += 1
                    current_sum = num
                    if splits > k:
                        return False
                else:
                    current_sum += num
            return True

        low = max(arr)
        high = sum(arr)

        while low < high:
            mid = (low + high) // 2
            if can_split(arr, k, mid):
                high = mid
            else:
                low = mid + 1

        return low
