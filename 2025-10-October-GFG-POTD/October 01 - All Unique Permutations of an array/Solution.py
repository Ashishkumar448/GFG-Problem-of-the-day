from typing import List

class Solution:
    def uniquePerms(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        result = []
        used = [False] * len(arr)

        def backtrack(current):
            if len(current) == len(arr):
                result.append(current[:])
                return
            for i in range(len(arr)):
                if used[i]:
                    continue
                # Skip duplicates
                if i > 0 and arr[i] == arr[i - 1] and not used[i - 1]:
                    continue
                used[i] = True
                current.append(arr[i])
                backtrack(current)
                current.pop()
                used[i] = False

        backtrack([])
        return result


# Example usage:
# sol = Solution()
# print(sol.uniquePerms([1, 3, 3]))
# Output: [[1, 3, 3], [3, 1, 3], [3, 3, 1]]
