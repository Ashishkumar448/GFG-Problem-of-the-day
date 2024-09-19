class Solution:
    # Function to reverse words in a given string.
    def reverseWords(self, s: str) -> str:
        # Split the string by the dot (.) character
        words = s.split('.')
        # Reverse the list of words and join them with a dot
        return '.'.join(reversed(words))

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input().strip()
        obj = Solution()
        print(obj.reverseWords(s))
