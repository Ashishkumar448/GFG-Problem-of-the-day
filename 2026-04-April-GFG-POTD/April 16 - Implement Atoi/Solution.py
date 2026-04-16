class Solution:
    def myAtoi(self, s: str) -> int:
        i, n = 0, len(s)
        
        # 1. Skip leading whitespaces
        while i < n and s[i] == ' ':
            i += 1
        
        if i == n:
            return 0
        
        # 2. Check sign
        sign = 1
        if s[i] in ['+', '-']:
            sign = -1 if s[i] == '-' else 1
            i += 1
        
        # 3. Read digits
        result = 0
        
        while i < n and s[i].isdigit():
            digit = int(s[i])
            result = result * 10 + digit
            
            # 4. Handle overflow
            if sign * result > 2**31 - 1:
                return 2**31 - 1
            if sign * result < -2**31:
                return -2**31
            
            i += 1
        
        return sign * result
