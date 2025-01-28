class Solution:
    def findPermutation(self, s: str):
        result = []
        s = ''.join(sorted(s))  # Sort to handle duplicates easily
        used = [False] * len(s)
        self.backtrack(result, [], s, used)
        return result

    def backtrack(self, result, current, s, used):
        if len(current) == len(s):
            result.append(''.join(current))
            return

        for i in range(len(s)):
            # Skip already used characters
            if used[i]:
                continue

            # Skip duplicates (only use the first occurrence)
            if i > 0 and s[i] == s[i - 1] and not used[i - 1]:
                continue

            # Mark the character as used
            used[i] = True
            current.append(s[i])

            # Recursive call
            self.backtrack(result, current, s, used)

            # Backtrack
            current.pop()
            used[i] = False


# Driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S = input().strip()
        obj = Solution()
        ans = obj.findPermutation(S)
        ans.sort()
        print(" ".join(ans))
        print("~")
