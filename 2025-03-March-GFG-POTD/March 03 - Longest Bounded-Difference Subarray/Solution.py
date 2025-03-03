from sortedcontainers import SortedDict

class Solution:
    def longestSubarray(self, arr, x):
        n = len(arr)
        left, right = 0, 0
        maxLen, startIdx = 0, 0
        window = SortedDict()  # Maintains sorted elements in the window

        while right < n:
            window[arr[right]] = window.get(arr[right], 0) + 1

            # Shrink window if max-min > x
            while window and window.peekitem(-1)[0] - window.peekitem(0)[0] > x:
                window[arr[left]] -= 1
                if window[arr[left]] == 0:
                    del window[arr[left]]
                left += 1

            # Update max length and start index
            if right - left + 1 > maxLen:
                maxLen = right - left + 1
                startIdx = left

            right += 1

        return arr[startIdx:startIdx + maxLen]

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        x = int(input())

        obj = Solution()
        ans = obj.longestSubarray(arr, x)

        print(" ".join(map(str, ans)))
