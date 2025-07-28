class Solution:
    @staticmethod
    def balanceSums(mat):
        n = len(mat)
        row_sum = [0] * n
        col_sum = [0] * n
        max_sum = 0

        # Calculate row and column sums
        for i in range(n):
            for j in range(n):
                row_sum[i] += mat[i][j]
                col_sum[j] += mat[i][j]

        # Determine the target sum (maximum row or column sum)
        for i in range(n):
            max_sum = max(max_sum, row_sum[i], col_sum[i])

        # Calculate number of operations needed
        operations = 0
        for i in range(n):
            operations += (max_sum - row_sum[i])

        return operations
