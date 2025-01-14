class Solution:
    def maxWater(self, arr):
        left = 0  # Left pointer
        right = len(arr) - 1  # Right pointer
        maxWater = 0  # To store the maximum water

        while left < right:
            # Calculate the water between the current pair of lines
            height = min(arr[left], arr[right])
            width = right - left
            currentWater = height * width

            # Update the maximum water if the current one is greater
            maxWater = max(maxWater, currentWater)

            # Move the pointer pointing to the shorter line inward
            if arr[left] < arr[right]:
                left += 1
            else:
                right -= 1

        return maxWater


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.maxWater(arr))
        print("~")
