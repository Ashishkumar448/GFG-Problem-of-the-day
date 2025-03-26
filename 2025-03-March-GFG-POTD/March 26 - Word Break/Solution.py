class Solution:
    def __init__(self):
        self.wordSet = set()
        self.memo = {}

    def canBreak(self, s):
        if not s:
            return True
        if s in self.memo:
            return self.memo[s]

        for i in range(1, len(s) + 1):
            prefix = s[:i]
            if prefix in self.wordSet and self.canBreak(s[i:]):
                self.memo[s] = True
                return True

        self.memo[s] = False
        return False

    def wordBreak(self, s, dictionary):
        self.wordSet = set(dictionary)
        self.memo = {}
        return self.canBreak(s)

# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input().strip()
        dictionary = input().strip().split()
        obj = Solution()
        print("true" if obj.wordBreak(s, dictionary) else "false")
        print("~")
