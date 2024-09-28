# { Driver Code Starts
from collections import deque

class Solution:
    # Function to find maximum of each subarray of size k.
    def max_of_subarrays(self, arr, n, k):
        result = []
        dq = deque()

        for i in range(n):
            # Remove elements not part of this window (out of bounds for subarray)
            if dq and dq[0] <= i - k:
                dq.popleft()

            # Remove elements from the deque that are smaller than the current element,
            # because they will not be the maximum for any future subarray.
            while dq and arr[dq[-1]] <= arr[i]:
                dq.pop()

            # Add the current element index at the back of the deque
            dq.append(i)

            # The maximum of the current window is at the front of the deque
            if i >= k - 1:
                result.append(arr[dq[0]])

        return result


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.max_of_subarrays(arr, n, k)
        print(" ".join(map(str, res)))
# } Driver Code Ends
