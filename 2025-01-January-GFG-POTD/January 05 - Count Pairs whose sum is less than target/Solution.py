class Solution:
    def countPairs(self, arr, target):
        # Sort the array
        arr.sort()
        count = 0
        left, right = 0, len(arr) - 1

        # Use two pointers
        while left < right:
            sum_ = arr[left] + arr[right]
            if sum_ < target:
                # If the sum is less than the target,
                # all pairs (arr[left], arr[left + 1], ..., arr[right]) are valid
                count += (right - left)
                left += 1
            else:
                right -= 1  # Decrease right to reduce the sum
        return count


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        nums = list(map(int, input().strip().split()))
        target = int(input().strip())

        obj = Solution()
        print(obj.countPairs(nums, target))
        print("~")
