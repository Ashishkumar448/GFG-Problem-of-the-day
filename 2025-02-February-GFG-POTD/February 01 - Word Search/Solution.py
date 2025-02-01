class Solution:
    # Directions for moving in the grid (right, down, left, up)
    rowDir = [0, 1, 0, -1]
    colDir = [1, 0, -1, 0]

    def isWordExist(self, mat, word):
        n = len(mat)
        m = len(mat[0])

        # Iterate through all cells to start DFS
        for i in range(n):
            for j in range(m):
                # Start DFS if the first character matches
                if mat[i][j] == word[0]:
                    visited = [[False for _ in range(m)] for _ in range(n)]
                    if self.dfs(mat, word, 0, i, j, visited):
                        return True
        return False

    # DFS helper function
    def dfs(self, mat, word, index, row, col, visited):
        # If index matches word length, we've found the word
        if index == len(word):
            return True

        # Check bounds and if the cell is already visited or doesn't match
        if row < 0 or col < 0 or row >= len(mat) or col >= len(mat[0]) or visited[row][col] or mat[row][col] != word[index]:
            return False

        # Mark the current cell as visited
        visited[row][col] = True

        # Explore all 4 possible directions (right, down, left, up)
        for i in range(4):
            newRow = row + self.rowDir[i]
            newCol = col + self.colDir[i]
            if self.dfs(mat, word, index + 1, newRow, newCol, visited):
                return True

        # Backtrack: unmark the current cell as visited
        visited[row][col] = False
        return False


# Driver code
if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n, m = map(int, input().split())
        mat = [list(input().strip()) for _ in range(n)]
        word = input().strip()

        sol = Solution()
        if sol.isWordExist(mat, word):
            print("true")
        else:
            print("false")
        print("~")
