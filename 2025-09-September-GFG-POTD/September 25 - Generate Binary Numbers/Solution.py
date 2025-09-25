class Solution:
    def generateBinary(self, n: int) -> list[str]:
        result = []
        for i in range(1, n + 1):
            result.append(bin(i)[2:])  # remove '0b' prefix
        return result


# Example usage
sol = Solution()
n = 6
print(sol.generateBinary(n))  # ['1', '10', '11', '100', '101', '110']
