class Solution:
    # Function to check whether two strings are anagram of each other or not.
    def areAnagrams(self, s1: str, s2: str) -> bool:
        # If lengths are different, they can't be anagrams
        if len(s1) != len(s2):
            return False
        
        # Frequency array for counting character occurrences (a-z)
        count = [0] * 26
        
        # Count characters in s1 and s2
        for i in range(len(s1)):
            count[ord(s1[i]) - ord('a')] += 1  # Increment count for s1 character
            count[ord(s2[i]) - ord('a')] -= 1  # Decrement count for s2 character
        
        # If any element is non-zero, the strings are not anagrams
        return all(c == 0 for c in count)

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s1 = input()
        s2 = input()

        obj = Solution()
        if obj.areAnagrams(s1, s2):
            print("true")
        else:
            print("false")
        print("~")
