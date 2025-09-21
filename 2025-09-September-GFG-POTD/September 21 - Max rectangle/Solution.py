class Solution:
    def maxArea(self, mat):
        if not mat or not mat[0]:
            return 0

        n, m = len(mat), len(mat[0])
        heights = [0] * m
        max_area = 0

        for i in range(n):
            # update histogram heights
            for j in range(m):
                if mat[i][j] == 0:
                    heights[j] = 0
                else:
                    heights[j] += 1

            # largest rectangle in histogram
            stack = []
            for j in range(m + 1):
                h = 0 if j == m else heights[j]
                while stack and h < heights[stack[-1]]:
                    height = heights[stack.pop()]
                    width = j if not stack else j - stack[-1] - 1
                    max_area = max(max_area, height * width)
                stack.append(j)

        return max_area


# Example usage:
# mat = [[0,1,1,0],
#        [1,1,1,1],
#        [1,1,1,1],
#        [1,1,0,0]]
# sol = Solution()
# print(sol.maxArea(mat))  # Output: 8
