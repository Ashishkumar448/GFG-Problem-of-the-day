class Solution:
    def maxCircularSum(self, arr):
        def kadane(nums):
            max_so_far = nums[0]
            current_max = nums[0]
            for num in nums[1:]:
                current_max = max(num, current_max + num)
                max_so_far = max(max_so_far, current_max)
            return max_so_far

        max_kadane = kadane(arr)
        total_sum = sum(arr)
        inverted_arr = [-x for x in arr]
        max_inverse_kadane = kadane(inverted_arr)
        max_wrap = total_sum + max_inverse_kadane

        if max_wrap == 0:
            return max_kadane

        return max(max_kadane, max_wrap)
