class Solution:
    def canFormPalindrome(self, s: str) -> bool:
        freq = [0] * 26
        
        # Count frequency
        for c in s:
            freq[ord(c) - ord('a')] += 1
        
        odd_count = 0
        
        # Count odd frequencies
        for count in freq:
            if count % 2 != 0:
                odd_count += 1
        
        return odd_count <= 1
