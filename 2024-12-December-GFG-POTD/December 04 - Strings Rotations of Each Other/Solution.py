class Solution:
    # Function to check if two strings are rotations of each other or not.
    def areRotations(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        # Concatenate s1 with itself
        concatenated = s1 + s1

        # Use KMP to check if s2 is a substring of concatenated string
        return self.kmpSearch(concatenated, s2)
    
    # KMP algorithm to check if pattern is a substring of text
    def kmpSearch(self, text: str, pattern: str) -> bool:
        lps = self.computeLPSArray(pattern)
        i = j = 0  # Indexes for text and pattern

        while i < len(text):
            if pattern[j] == text[i]:
                i += 1
                j += 1
            
            if j == len(pattern):
                return True  # Pattern found
            elif i < len(text) and pattern[j] != text[i]:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        return False
    
    # Compute the longest prefix-suffix (LPS) array for the pattern
    def computeLPSArray(self, pattern: str) -> list:
        lps = [0] * len(pattern)
        length = 0
        i = 1

        while i < len(pattern):
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        return lps

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s1 = input().strip()
        s2 = input().strip()
        obj = Solution()
        if obj.areRotations(s1, s2):
            print("true")
        else:
            print("false")
