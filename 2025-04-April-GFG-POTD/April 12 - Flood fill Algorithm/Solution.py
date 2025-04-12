class Solution:
    def floodFill(self, image, sr, sc, newColor):
        originalColor = image[sr][sc]
        if originalColor == newColor:
            return image

        def dfs(r, c):
            if r < 0 or c < 0 or r >= len(image) or c >= len(image[0]) or image[r][c] != originalColor:
                return
            image[r][c] = newColor
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

        dfs(sr, sc)
        return image

# Example usage
image = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]]
sr, sc, newColor = 1, 2, 2
sol = Solution()
result = sol.floodFill(image, sr, sc, newColor)

for row in result:
    print(" ".join(map(str, row)))
