class Solution:
    def longestStringChain(self, words):
        # Sort words based on length
        words.sort(key=len)
        
        dp = {}  # Dictionary to store the longest chain ending at each word
        maxChain = 1

        for word in words:
            longest = 1  # A word itself is a chain of length 1

            for i in range(len(word)):
                prev = word[:i] + word[i+1:]  # Remove one character
                
                if prev in dp:
                    longest = max(longest, dp[prev] + 1)

            dp[word] = longest
            maxChain = max(maxChain, longest)

        return maxChain


# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        words = input().strip().split()
        obj = Solution()
        print(obj.longestStringChain(words))
