# Python Version

class Solution:
    def multiplyStrings(self, s1: str, s2: str) -> str:
        isNegative = False
        
        if s1[0] == '-':
            isNegative = not isNegative
            s1 = s1[1:]
        if s2[0] == '-':
            isNegative = not isNegative
            s2 = s2[1:]
        
        s1 = self.removeLeadingZeros(s1)
        s2 = self.removeLeadingZeros(s2)

        if s1 == "0" or s2 == "0":
            return "0"

        n = len(s1)
        m = len(s2)
        result = [0] * (n + m)

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                mul = (ord(s1[i]) - ord('0')) * (ord(s2[j]) - ord('0'))
                sum_ = mul + result[i + j + 1]

                result[i + j + 1] = sum_ % 10
                result[i + j] += sum_ // 10

        i = 0
        while i < len(result) and result[i] == 0:
            i += 1

        ans = ''.join(map(str, result[i:]))

        if isNegative:
            ans = '-' + ans

        return ans

    def removeLeadingZeros(self, s: str) -> str:
        i = 0
        while i < len(s) and s[i] == '0':
            i += 1
        return "0" if i == len(s) else s[i:]

# Example Driver Code
if __name__ == "__main__":
    t = int(input())
    while t > 0:
        a = input().strip()
        b = input().strip()
        sol = Solution()
        print(sol.multiplyStrings(a, b))
        print("~")
        t -= 1
