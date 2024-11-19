class Solution:
    def nextPermutation(self, nums):
        n = len(nums)
        i = n - 2

        # Step 1: Find the first decreasing element from the right
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        if i >= 0:
            # Step 2: Find the smallest element larger than nums[i] from the right
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1

            # Step 3: Swap nums[i] and nums[j]
            nums[i], nums[j] = nums[j], nums[i]

        # Step 4: Reverse the elements to the right of i
        nums[i + 1:] = reversed(nums[i + 1:])

if __name__ == "__main__":
    tc = int(input()) # Number of test cases
    for _ in range(tc):
        nums = list(map(int, input().split()))
        obj = Solution()
        obj.nextPermutation(nums) # Generate the next permutation
        print(" ".join(map(str, nums)))
        print("~")
