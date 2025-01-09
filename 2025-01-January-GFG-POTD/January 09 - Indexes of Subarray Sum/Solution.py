class Solution:
    def subarraySum(self, arr, target):
        result = []
        n = len(arr)
        current_sum = 0
        start = 0

        for end in range(n):
            # Add current element to the current sum
            current_sum += arr[end]

            # Shrink the window while the current sum is greater than the target
            while current_sum > target and start <= end:
                current_sum -= arr[start]
                start += 1

            # Check if the current sum equals the target
            if current_sum == target:
                result.append(start + 1)  # 1-based index
                result.append(end + 1)    # 1-based index
                return result

        # If no subarray is found, return [-1]
        return [-1]


# Driver Code
if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        arr = list(map(int, input().split()))
        target = int(input())
        ob = Solution()
        result = ob.subarraySum(arr, target)
        print(" ".join(map(str, result)))
