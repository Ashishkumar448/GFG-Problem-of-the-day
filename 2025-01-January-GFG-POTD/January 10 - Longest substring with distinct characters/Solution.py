class Solution:
    def longestUniqueSubstr(self, s: str) -> int:
        if not s:
            return 0

        last_seen = {}
        max_length = 0
        start = 0

        for end, current_char in enumerate(s):
            # If the character is already in the map, update the start index
            if current_char in last_seen:
                start = max(start, last_seen[current_char] + 1)

            # Update the last seen index of the current character
            last_seen[current_char] = end

            # Calculate the current window length and update max_length
            max_length = max(max_length, end - start + 1)

        return max_length


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        ob = Solution()
        print(ob.longestUniqueSubstr(s))
        print("~")
