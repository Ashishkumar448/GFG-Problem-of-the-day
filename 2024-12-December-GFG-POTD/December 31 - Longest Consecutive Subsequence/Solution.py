class Solution:
    def longestConsecutive(self, arr):
        if not arr:
            return 0  # Edge case: Empty array

        num_set = set(arr)
        longest_streak = 0

        for num in num_set:
            # Check if it's the start of a sequence
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                # Count the length of the sequence
                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1

                # Update the longest streak
                longest_streak = max(longest_streak, current_streak)

        return longest_streak


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.longestConsecutive(arr))
