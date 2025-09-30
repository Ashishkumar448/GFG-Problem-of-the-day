class Solution:
    def binstr(self, n: int):
        result = []
        total = 1 << n  # 2^n
        for i in range(total):
            binary = bin(i)[2:]  # remove '0b' prefix
            binary = binary.zfill(n)  # pad with leading zeros
            result.append(binary)
        return result


# Example usage
sol = Solution()
print(sol.binstr(3))  # ['000', '001', '010', '011', '100', '101', '110', '111']
