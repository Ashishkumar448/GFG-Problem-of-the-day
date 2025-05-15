class Solution:
    def countSubstring(self, s: str) -> int:
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1

        count = 0
        for f in freq:
            count += (f * (f + 1)) // 2

        return count

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        ob = Solution()
        result = ob.countSubstring(s)
        print(result)
        print("~")
