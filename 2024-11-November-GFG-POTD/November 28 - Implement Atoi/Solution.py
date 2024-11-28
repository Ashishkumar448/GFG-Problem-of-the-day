class Solution:
    def myAtoi(self, s: str) -> int:
        i, n = 0, len(s)
        if n == 0:
            return 0

        # Step 1: Skip leading whitespaces
        while i < n and s[i] == ' ':
            i += 1

        # Step 2: Check if the string is entirely whitespaces
        if i == n:
            return 0

        # Step 3: Check for sign
        sign = 1  # Default positive
        if s[i] == '+' or s[i] == '-':
            sign = -1 if s[i] == '-' else 1
            i += 1

        # Step 4: Read digits and build the number
        result = 0
        while i < n:
            if not s[i].isdigit():
                break
            
            digit = int(s[i])

            # Step 5: Check for overflow before updating result
            if result > (2**31 - 1 - digit) // 10:
                return (2**31 - 1) if sign == 1 else -(2**31)
            
            result = result * 10 + digit
            i += 1

        return result * sign

# Example Usage
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        obj = Solution()
        num = obj.myAtoi(s)
        print(num)
        print("~")
