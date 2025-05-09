class Solution:
    def __init__(self):
        self.max_str = ""

    def findMaximumNum(self, s, k):
        self.max_str = s
        self.findMaxHelper(list(s), k, 0)
        return self.max_str

    def findMaxHelper(self, s, k, idx):
        if k == 0 or idx == len(s):
            return

        max_digit = max(s[idx:])
        if max_digit != s[idx]:
            for i in range(len(s) - 1, idx, -1):
                if s[i] == max_digit:
                    s[idx], s[i] = s[i], s[idx]
                    curr = ''.join(s)
                    if curr > self.max_str:
                        self.max_str = curr

                    self.findMaxHelper(s, k - 1, idx + 1)
                    s[idx], s[i] = s[i], s[idx]  # backtrack
        else:
            self.findMaxHelper(s, k, idx + 1)

# Example usage
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        s = input().strip()
        obj = Solution()
        print(obj.findMaximumNum(s, k))
        print("~")
