from collections import defaultdict

class Solution:
    def countSubarrays(self, arr, k):
        prefix_sum_count = defaultdict(int)
        current_sum = 0
        count = 0

        # Initialize the prefix sum count with 0 sum
        prefix_sum_count[0] = 1

        for num in arr:
            current_sum += num

            # Check if there exists a prefix sum such that currentSum - prefixSum = k
            if current_sum - k in prefix_sum_count:
                count += prefix_sum_count[current_sum - k]

            # Update the frequency of the current prefix sum in the map
            prefix_sum_count[current_sum] += 1

        return count

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        k = int(input())
        arr = list(map(int, input().split()))

        sol = Solution()
        res = sol.countSubarrays(arr, k)

        print(res)
        print("~")
