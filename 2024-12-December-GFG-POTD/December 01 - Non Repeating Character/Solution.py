class Solution:
    # Function to find the first non-repeating character in a string.
    def nonRepeatingChar(self, s: str) -> str:
        # Step 1: Create a frequency map to count occurrences of each character
        freq_map = {}
        
        # Step 2: Populate the frequency map
        for c in s:
            freq_map[c] = freq_map.get(c, 0) + 1
        
        # Step 3: Traverse the string again to find the first non-repeating character
        for c in s:
            if freq_map[c] == 1:
                return c  # Return the first non-repeating character
        
        # Step 4: If no non-repeating character is found, return '$'
        return '$'

# Driver code
if __name__ == "__main__":
    t = int(input())
    
    for _ in range(t):
        s = input()
        
        obj = Solution()
        ans = obj.nonRepeatingChar(s)
        
        if ans != '$':
            print(ans)
        else:
            print(-1)
        print("~")
