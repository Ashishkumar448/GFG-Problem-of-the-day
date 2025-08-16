class Solution:
    def findLargest(self, arr):
        # Step 1: Convert to string
        nums = list(map(str, arr))

        # Step 2: Sort using custom comparator
        from functools import cmp_to_key
        def compare(a, b):
            if a + b > b + a:
                return -1  # a before b
            elif a + b < b + a:
                return 1   # b before a
            else:
                return 0
        nums.sort(key=cmp_to_key(compare))

        # Step 3: Handle leading zeros
        if nums[0] == "0":
            return "0"

        # Step 4: Build result
        return "".join(nums)
