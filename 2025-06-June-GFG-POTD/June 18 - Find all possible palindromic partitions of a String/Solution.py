class Solution:
    def palinParts(self, s: str):
        result = []
        self.backtrack(s, 0, [], result)
        return result

    def backtrack(self, s, start, current, result):
        if start == len(s):
            result.append(current[:])  # deep copy
            return

        for end in range(start + 1, len(s) + 1):
            substring = s[start:end]
            if self.isPalindrome(substring):
                current.append(substring)
                self.backtrack(s, end, current, result)
                current.pop()  # backtrack

    def isPalindrome(self, s):
        return s == s[::-1]
