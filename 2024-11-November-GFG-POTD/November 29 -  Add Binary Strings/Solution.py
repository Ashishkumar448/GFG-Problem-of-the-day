class Solution:
    def addBinary(self, s1: str, s2: str) -> str:
        result = []
        i, j = len(s1) - 1, len(s2) - 1
        carry = 0

        # Traverse both strings starting from their rightmost digits
        while i >= 0 or j >= 0 or carry > 0:
            sum_ = carry

            if i >= 0:
                sum_ += int(s1[i])  # Add s1's digit
                i -= 1
            if j >= 0:
                sum_ += int(s2[j])  # Add s2's digit
                j -= 1

            result.append(str(sum_ % 2))  # Append current bit (0 or 1)
            carry = sum_ // 2             # Update carry

        # Reverse the result as the current string is in reverse order
        result.reverse()

        # Remove leading zeros
        return ''.join(result).lstrip('0') or '0'

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a = input().strip()
        b = input().strip()
        ob = Solution()
        print(ob.addBinary(a, b))
        print("~")
