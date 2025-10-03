class Solution:
    KEYPAD = [
        "",     # 0
        "",     # 1
        "abc",  # 2
        "def",  # 3
        "ghi",  # 4
        "jkl",  # 5
        "mno",  # 6
        "pqrs", # 7
        "tuv",  # 8
        "wxyz"  # 9
    ]

    def possibleWords(self, arr):
        result = []

        def backtrack(index, current):
            if index == len(arr):
                if current:  # only add non-empty
                    result.append(current)
                return

            letters = self.KEYPAD[arr[index]]
            if not letters:  # skip 0 and 1
                backtrack(index + 1, current)
                return

            for ch in letters:
                backtrack(index + 1, current + ch)

        backtrack(0, "")
        return result


# Example usage
# sol = Solution()
# print(sol.possibleWords([8, 8, 1]))
# Output: ['tt', 'tu', 'tv', 'ut', 'uu', 'uv', 'vt', 'vu', 'vv']
