class Solution:
    def isSumString(self, s: str) -> bool:
        n = len(s)
        for i in range(1, n):
            for j in range(i + 1, n):
                num1 = s[:i]
                num2 = s[i:j]
                if self.is_valid(num1) and self.is_valid(num2):
                    if self.check(s[j:], num1, num2):
                        return True
        return False

    def is_valid(self, num: str) -> bool:
        return not (len(num) > 1 and num[0] == '0')

    def check(self, remaining: str, num1: str, num2: str) -> bool:
        sum_str = self.add_strings(num1, num2)
        if not remaining.startswith(sum_str):
            return False
        if remaining == sum_str:
            return True
        return self.check(remaining[len(sum_str):], num2, sum_str)

    def add_strings(self, num1: str, num2: str) -> str:
        result = []
        carry = 0
        i, j = len(num1) - 1, len(num2) - 1
        while i >= 0 or j >= 0 or carry:
            digit1 = int(num1[i]) if i >= 0 else 0
            digit2 = int(num2[j]) if j >= 0 else 0
            total = digit1 + digit2 + carry
            result.append(str(total % 10))
            carry = total // 10
            i -= 1
            j -= 1
        return ''.join(reversed(result))
