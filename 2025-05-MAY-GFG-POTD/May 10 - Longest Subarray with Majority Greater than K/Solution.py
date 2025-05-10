class Solution:
    def longestSubarray(self, arr, k):
        n = len(arr)
        temp = [1 if x > k else -1 for x in arr]

        prefix_sum = 0
        max_length = 0
        prefix_map = {}

        for i in range(n):
            prefix_sum += temp[i]

            if prefix_sum > 0:
                max_length = i + 1
            else:
                if prefix_sum not in prefix_map:
                    prefix_map[prefix_sum] = i

                if (prefix_sum - 1) in prefix_map:
                    max_length = max(max_length, i - prefix_map[prefix_sum - 1])

        return max_length

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        k = int(input())
        sol = Solution()
        print(sol.longestSubarray(arr, k))
        print("~")
