def longestPalindrome(s):
    if not s:
        return ""
    
    start = 0
    max_len = 0
    
    def expand(left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1  # Actual palindrome length
    
    for i in range(len(s)):
        len1 = expand(i, i)      # Odd-length palindromes
        len2 = expand(i, i + 1)  # Even-length palindromes
        current_len = max(len1, len2)
        
        if current_len > max_len:
            max_len = current_len
            # Calculate start index based on expansion type
            if len1 > len2:
                start = i - (len1 - 1) // 2
            else:
                start = i - (len2 // 2 - 1)
    
    return s[start:start + max_len]
