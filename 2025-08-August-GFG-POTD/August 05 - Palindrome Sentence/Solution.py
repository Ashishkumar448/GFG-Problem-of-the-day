class Solution:
    def isPalinSent(self, s: str) -> bool:
        # Step 1: Normalize the string
        cleaned = ''.join(c.lower() for c in s if c.isalnum())
        
        # Step 2: Check if it's a palindrome
        return cleaned == cleaned[::-1]
