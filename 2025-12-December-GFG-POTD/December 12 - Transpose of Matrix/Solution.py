class Solution:
    def transpose(self, mat):
        n = len(mat)
        result = []

        for i in range(n):
            row = []
            for j in range(n):
                row.append(mat[j][i])  # swap row/column
            result.append(row)

        return result
