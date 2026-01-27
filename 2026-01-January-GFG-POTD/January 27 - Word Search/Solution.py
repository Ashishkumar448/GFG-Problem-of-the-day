class Solution:
    def isWordExist(self, mat, word):
        n = len(mat)
        m = len(mat[0])
        
        visited = [[False] * m for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                if mat[i][j] == word[0]:
                    if self.dfs(mat, word, i, j, 0, visited):
                        return True
        return False

    def dfs(self, mat, word, i, j, index, visited):
        # All characters matched
        if index == len(word):
            return True
        
        # Boundary and mismatch checks
        if (i < 0 or j < 0 or i >= len(mat) or j >= len(mat[0]) or
            visited[i][j] or mat[i][j] != word[index]):
            return False
        
        visited[i][j] = True
        
        found = (
            self.dfs(mat, word, i + 1, j, index + 1, visited) or
            self.dfs(mat, word, i - 1, j, index + 1, visited) or
            self.dfs(mat, word, i, j + 1, index + 1, visited) or
            self.dfs(mat, word, i, j - 1, index + 1, visited)
        )
        
        visited[i][j] = False  # backtrack
        
        return found
