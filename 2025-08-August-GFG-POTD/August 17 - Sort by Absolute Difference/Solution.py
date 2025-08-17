class Solution:
    def rearrange(self, arr, x):
        # Python's sorted() is stable, so equal diffs keep original order
        arr.sort(key=lambda num: abs(num - x))
        return arr


# Example usage
arr = [10, 5, 3, 9, 2]
x = 7
sol = Solution()
sol.rearrange(arr, x)
print(arr)  # Output: [5, 9, 10, 3, 2]
