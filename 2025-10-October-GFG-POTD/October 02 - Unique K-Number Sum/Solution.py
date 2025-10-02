class Solution:
    def combinationSum(self, n: int, k: int):
        result = []
        def backtrack(temp, start, total):
            if len(temp) == k:
                if total == n:
                    result.append(temp[:])
                return
            
            for i in range(start, 10):
                if total + i > n:
                    break  # pruning
                temp.append(i)
                backtrack(temp, i + 1, total + i)
                temp.pop()
        
        backtrack([], 1, 0)
        return result

# Example usage:
# sol = Solution()
# print(sol.combinationSum(9, 3))  
# Output: [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
