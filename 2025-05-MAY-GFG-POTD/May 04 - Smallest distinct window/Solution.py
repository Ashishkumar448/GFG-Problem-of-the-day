class Solution:
    def findSubString(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0

        unique_chars = set(s)
        total_unique = len(unique_chars)

        freq_map = {}
        min_len = float('inf')
        start = 0
        count = 0

        for end in range(n):
            end_char = s[end]
            freq_map[end_char] = freq_map.get(end_char, 0) + 1
            if freq_map[end_char] == 1:
                count += 1

            while count == total_unique:
                min_len = min(min_len, end - start + 1)
                start_char = s[start]
                freq_map[start_char] -= 1
                if freq_map[start_char] == 0:
                    count -= 1
                start += 1

        return min_len

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input().strip()
        obj = Solution()
        print(obj.findSubString(s))
        print("~")
