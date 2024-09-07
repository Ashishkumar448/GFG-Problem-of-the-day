class Solution:
    def findNth(self, n: int) -> int:
        # Convert n to a number in base 9 to skip the digit 9
        result = 0
        place = 1

        # Continue until n is reduced to zero
        while n > 0:
            # Append the remainder when divided by 9 to the result
            result += (n % 9) * place
            # Move to the next digit
            n //= 9
            # Update the place value to the next power of 10
            place *= 10
        
        return result

# Driver Code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        obj = Solution()
        print(obj.findNth(n))
